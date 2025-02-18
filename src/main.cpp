#include <iostream>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
// #include <ftxui/screen/string.hpp>

int main() {
    using namespace ftxui;

    Element textBox = hbox({
        text(L"Hello, World!") | border | bold
    });

    Screen display = Screen::Create(Dimension::Full(), Dimension::Fit(textBox));
    Render(display, textBox);
    std::cout << display.ToString() << std::endl;

    return 0;
}