#ifndef __BUTTONMAKER_H__
#define __BUTTONMAKER_H__
#include <ftxui/component/component.hpp>
#include <string>

class ButtonMaker {
    public:
        ButtonMaker() = delete;
        static ftxui::ButtonOption Style() {
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
        }

        static ftxui::Component MakeButton(const std::string& text, std::string& inputStr, ftxui::ScreenInteractive& screen) {
            return ftxui::Button(
              text,
              [&] {
                inputStr = text;
                screen.ExitLoopClosure()();
              },
              Style()
            );
        }
};

#endif