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
      string Displaystart() const;
      string DisplayClassSelection() const;
      string DisplayGameOver() const;
      string DisplayVictory() const;
      void Displaylvlup();
        //just display lvl up options
};

#endif