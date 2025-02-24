#ifndef __MENUDISPLAY_H__
#define __MENUDISPLAY_H__

#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
// #include <ftxui/screen/string.hpp>
# include <ftxui/component/component.hpp>
# include <ftxui/component/event.hpp>
# include <ftxui/component/screen_interactive.hpp>
# include <ftxui/component/loop.hpp>

#include <vector>
#include <string>
using namespace std;
using namespace ftxui;

ButtonOption Style() {
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

class MenuDisplay {
    public:

      string Displaystart() const{
        string playerInput = "";
        auto screen = ScreenInteractive::FitComponent();
  
        auto newgameb = Button("New Game", [&] { playerInput = "Start"; screen.ExitLoopClosure()(); }, Style()); //to screen.charcostumization()
        auto loadgameb = Button("Continue Load Game", [&] { playerInput = "Continue"; screen.ExitLoopClosure()(); }, Style()); //to screen.ingame()
        auto quitb = Button("Quit", [&] { playerInput = "Quit"; screen.ExitLoopClosure()(); }, Style());
     
        // The tree of components. This defines how to navigate using the keyboard.
        // The selected `row` is shared to get a grid layout.
        int row = 0;
        auto buttons = Container::Vertical({
          newgameb | flex,
          loadgameb | flex,
          quitb | flex
        });
     
        // Modify the way to render them on screen:
        auto renderer = Renderer(buttons, [&] {
          return vbox({
                    text("Sparky the Dragon!") | center | bold,
                    separator(),
                    buttons->Render() | flex,
                }) | flex | border;
        });
    
        screen.Loop(renderer);
        return playerInput;
      };
      string DisplayClassSelection() const{
        string playerInput = "";
        auto screen = ScreenInteractive::FitComponent();
  
        auto brawlerb = Button("Brawler", [&] { playerInput = "Brawler"; screen.ExitLoopClosure()(); }, Style());
        auto shooterb = Button("Shooter", [&] { playerInput = "Shooter"; screen.ExitLoopClosure()(); }, Style()); 
        auto fighterb = Button("Fighter", [&] { playerInput = "Fighter"; screen.ExitLoopClosure()(); }, Style());
     
        // The tree of components. This defines how to navigate using the keyboard.
        // The selected `row` is shared to get a grid layout.
        int row = 0;
        auto buttons = Container::Vertical({
          brawlerb | flex,
          shooterb | flex,
          fighterb | flex
        });

        //discription of classes
        Element textBox = vbox({
          text(L"Discription") | flex | bold,
          separator(),
          text(L"Brawler, More defence") | flex,
          separator(),
          text(L"Shooter, more  strength") | flex,
          separator(),
          text(L"Fighter, more agility") | flex,
        }) | border;
        //make this shit to the right
        
        Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
        Render(display, textBox);
        cout << display.ToString() << endl;
     
        // Modify the way to render them on screen:
        auto renderer = Renderer(buttons, [&] {
          return vbox({
                    text("Pick your class!") | center | bold,
                    separator(),
                    buttons->Render() | flex,
                }) | flex | border;
        });
        screen.Loop(renderer);
        return playerInput;
      };
      string DisplayGameOver() const;
        //display game over 
        //have option to quit game or continue from last save (2 options)
      void Displaylvlup();
        //just display lvl up options
};

#endif