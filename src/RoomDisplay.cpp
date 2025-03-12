#include "../header/RoomDisplay.h"
#include "../header/Room.h"
#include "../header/Character.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <string>

using namespace ftxui;

std::string RoomDisplay::DisplayRoom(Room room, Character player) {
    std::string playerChoice = "";
    auto screen = ScreenInteractive::FitComponent();  

    //  Extract Room Information 
    std::string description = room.GetDescription();
    std::vector<std::string> options = room.GetOptions();

 
    auto descriptionBox = vbox({
        text("Room Description") | bold | center,
        separator(),
        text(description) | flex
    }) | border;

    
    bool showInfo = false;
    bool showStats = false;

    auto infoDisplay = Renderer([&] {
        return showInfo ? vbox(text("Player Info:\n- Level: " + std::to_string(player.GetLevel())) | border)
                        : vbox();
    });

    auto statsDisplay = Renderer([&] {
        return showStats ? vbox(text("Stats:\n- HP: " + std::to_string(player.GetCurrHp())) | border)
                         : vbox();
    });

    auto infoButton = Button("Info", [&] {
        showInfo = !showInfo;  // Toggle visibility
        screen.PostEvent(Event::Custom);
    });

    auto statsButton = Button("Stats", [&] {
        showStats = !showStats;  // Toggle visibility
        screen.PostEvent(Event::Custom);
    });

    auto sidePanel = Container::Vertical({
        infoButton,
        infoDisplay,
        statsButton,
        statsDisplay
    });


    std::vector<Component> choiceButtons;
    for (const auto& option : options) {
        choiceButtons.push_back(Button(option, [&] {
            playerChoice = option;
            screen.PostEvent(Event::Custom); // Update UI without exiting
        }));
    }

    
    auto healthPotButton = Button("Health Pot", [&] {
        playerChoice = "Health Pot";
        screen.PostEvent(Event::Custom);
    });

   
    auto quitButton = Button("Quit Game", [&] {
        playerChoice = "Quit";
        screen.PostEvent(Event::Custom);
    });
    
    auto buttonRow = Container::Horizontal(choiceButtons);
    buttonRow->Add(healthPotButton);
    buttonRow->Add(quitButton);


    auto layout = Container::Vertical({
        Renderer([&] { return hbox({descriptionBox | flex, sidePanel->Render()}) | border; }),
        Renderer([&] { return separator(); }),
        buttonRow
    });

    screen.Loop(layout);  

    return playerChoice;
}

