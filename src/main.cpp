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
  }

int main() {
    Element textBox = hbox({
        text(L"Hello, World!") | border | bold
    });

    Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
    Render(display, textBox);
    cout << display.ToString() << endl;

    //MainMenu Display
    string playerInput = "";
    auto screen = ScreenInteractive::FitComponent();
   
    // clang-format off
    auto btn_dec_01 = Button("New Game", [&] { playerInput = "Start"; screen.ExitLoopClosure()(); }, Style()); //to screen.charcostumization()
    auto btn_inc_01 = Button("Continue Saved Game", [&] { playerInput = "Continue"; screen.ExitLoopClosure()(); }, Style()); //to screen.ingame()
    auto btn_dec_10 = Button("Quit", [&] { playerInput = "Quit"; screen.ExitLoopClosure()(); }, Style());
    // clang-format on
   
    // The tree of components. This defines how to navigate using the keyboard.
    // The selected `row` is shared to get a grid layout.
    int row = 0;
    auto buttons = Container::Vertical({
      btn_dec_01 | flex,
      btn_inc_01 | flex,
      btn_dec_10 | flex
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
    //akjndkfjandkjfnakdjn
    return 0;
}