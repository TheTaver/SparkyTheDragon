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
    void Displaystart() const{
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
                  //  text("option = " + playerInput) | center,
                  //  separator(),
                  buttons->Render() | flex,
               }) | flex | border;
      });
    
      screen.Loop(renderer);
    };
    string DisplayClassSelection() const;
    string DisplayGameOver() const;
    string Displaylvlup();
};


#endif