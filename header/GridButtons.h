#ifndef __GRIDBUTTONS_H__
#define __GRIDBUTTONS_H__
#include <ftxui/component/component.hpp>
#include <string>

#include "ButtonMaker.h"

using std::string;

class GridButtons {
    private:
        const int MAX_BUTTON_HEIGHT = 8;
        const int MAX_GRID_HEIGHT = 20;

        string* inputStr;
        ftxui::ScreenInteractive* screen;
        string text1;
        string text2;
        string text3;
        string text4;
        int row;
        int col1;
        int col2;

        // Make buttons fill in background & bold name when hovered/selected
        ftxui::ButtonOption HighlightButtonStyle() {
            using namespace ftxui;
            auto option = ButtonOption::Animated();
            option.transform = [](const EntryState& s) {
            auto element = text(s.label);
            if (s.focused) {
                element |= bold;
            }
            return element | center | borderEmpty | flex;
            };
            return option;
        };
            
        ftxui::Component MakeButton(const string& text) {
            return ButtonMaker::MakeButton(text, *inputStr, *screen);
        }

        void MakeGrid() {
            using namespace ftxui;
            btnGrid = Container::Vertical({
                Container::Horizontal({ MakeButton(text1), MakeButton(text2) }, &col1)
                    | size(HEIGHT, LESS_THAN, MAX_BUTTON_HEIGHT),
                Container::Horizontal({ MakeButton(text3), MakeButton(text4) }, &col2)
                    | size(HEIGHT, LESS_THAN, MAX_BUTTON_HEIGHT),
            }, &row)
                | size(HEIGHT, LESS_THAN, MAX_GRID_HEIGHT);
            
            btnGrid |= CatchEvent([&](Event event) {
                if (event == Event::ArrowDown) {
                // If moving down, go to button directly below the current one
                if(row < 1) {
                    // Moving down, make sure we go straight down
                    col2 = col1;
                    row++;
                    return true;
                }
                }
                else if(event == Event::ArrowUp) {
                // If moving up, go to button directly above the current one
                if(row > 0) {
                    // Moving up, make sure we go straight up
                    col1 = col2;
                    row--;
                    return true;
                }
                // Nowhere to move up
                }
                // Tells the button grid component whether we handled the event
                // We didn't do anything, so the button grid still needs to respond
                return false;
            });
        }
    public:
        ftxui::Component btnGrid;
        GridButtons(const string& t1, const string& t2, const string& t3, const string& t4, string* input, ftxui::ScreenInteractive* scrn) {
            text1 = t1;
            text2 = t2;
            text3 = t3;
            text4 = t4;
            row = 0;
            col1 = 0;
            col2 = 0;
            inputStr = input;
            screen = scrn;
            MakeGrid();
        }

};
#endif