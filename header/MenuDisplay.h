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

ButtonOption Style();

class MenuDisplay {
    public:
      string Displaystart() const;
      Element GetClassDescritption();
      string DisplayClassSelection() const;
      string DisplayGameOver() const;
      string DisplayVictory() const;
};

#endif