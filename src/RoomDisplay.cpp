#include "RoomDisplay.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <iostream>
#include "ButtonMaker.h"

using namespace ftxui;

std::string RoomDisplay::DisplayRoom(Room& room, Character& player, int currentHp) {
    auto screen = ScreenInteractive::TerminalOutput();
    std::string inputStr = "";

    // Use ButtonMaker for health potion and quit buttons
    Component healPotBtn = ButtonMaker::MakeButton("Health Pot", inputStr, screen);
    Component quit_game = ButtonMaker::MakeButton("Quit game", inputStr, screen);

    // Room Description Section
    auto room_description = Renderer([&] {
        return window(text("Room description"), text(room.GetDescription()));
    });

    // Info Panel
    auto info_panel = Renderer([&] {
        return window(text("Info"), text("Player: " + player.GetName()));
    });

    // Stats Panel
    auto stats_panel = Renderer([&] {
        return window(text("Stats"),
            vbox({
                text("HP: " + std::to_string(currentHp) + "/" + std::to_string(player.GetStat(0))),
                text("Attack: " + std::to_string(player.GetStat(1))),
                text("Speed: " + std::to_string(player.GetStat(2))),
                text("Defense: " + std::to_string(player.GetStat(3))),
            })
        );
    });

    // Creating buttons for choices
    std::vector<std::string> options = room.GetOptions();
    std::vector<Component> choice_buttons;

    for (const auto& option : options) {
        choice_buttons.push_back(ButtonMaker::MakeButton(option, inputStr, screen));
    }

    // Choices Layout
    auto choices_container = Container::Horizontal({});
    for (auto& button : choice_buttons) {
        choices_container->Add(button);
    }
    choices_container->Add(healPotBtn);

    // Main Layout
    auto layout = Container::Vertical({
        room_description,
        Container::Horizontal({
            info_panel,
            stats_panel
        }),
        choices_container,
        quit_game
    });

    auto render_layout = Renderer(layout, [&] {
        return window(text("Room Screen"), layout->Render());
    });

    screen.Loop(render_layout);

    return inputStr;  // ✅ Return player's choice instead of continuing execution
}
