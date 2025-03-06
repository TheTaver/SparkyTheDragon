#include "CombatUI.h"
#include "GridButtons.h"

using namespace ftxui;


using ftxui::Component;
using ftxui::Button;
using ftxui::ButtonOption;

// Make buttons fill in background & bold name when hovered/selected
ButtonOption CombatUI::HighlightButtonStyle() {
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
    
ftxui::Component CombatUI::MakeButton(const string& text) {
    // BROKEN SHIT: text string var needs to exist (in scope) when button is clicked on
    return Button(
      text,
      [&] {
        *userInputString = text;
        screen.ExitLoopClosure()();
      },
      HighlightButtonStyle()
    );
}

ftxui::Component CombatUI::QuadButtonMenu(const string& text1, const string& text2, const string& text3, const string& text4, BtnCoords& coords){
    // By default, when ftxui::Containers are selected, it automatically selects the last selected component inside it
    // This function overrides that behavior to mimic a 2x2 grid of buttons, instead of 2 containers of buttons
    // The BtnCoords object must exist, as its components are passed by reference to the buttons to track which are currently selected
    Component buttonGrid = Container::Vertical({
        Container::Horizontal({ MakeButton(text1), MakeButton(text2) }, &coords.col1),
        Container::Horizontal({ MakeButton(text3), MakeButton(text4) }, &coords.col2),
    }, &coords.row);

    // Override the arrow key events, to align the movements with the expected grid of buttons:
    buttonGrid |= CatchEvent([&](Event event) {
        if (event == Event::ArrowDown) {
          // If moving down, go to button directly below the current one
          if(coords.row < 1) {
            // Moving down, make sure we go straight down
            coords.col2 = coords.col1;
            coords.row++;
            return true;
          }
        }
        else if(event == Event::ArrowUp) {
          // If moving up, go to button directly above the current one
          if(coords.row > 0) {
            // Moving up, make sure we go straight up
            coords.col1 = coords.col2;
            coords.row--;
            return true;
          }
          // Nowhere to move up
        }
        // Tells the button grid component whether we handled the event
        // We didn't do anything, so the button grid still needs to respond
        return false;
      });
      return buttonGrid;
}


// Returns component for the quit button
Component CombatUI::GetQuitButton() {
    return Button("Quit Game", [&] { *userInputString = "Quit"; screen.ExitLoopClosure()(); }, HighlightButtonStyle());
}

Component CombatUI::GetMoveButtons(BtnCoords& coords) {
    const string move1 = playerChar->GetMoves().at(0).name;
    if(playerChar->GetMoves().size() == 1) {
        return QuadButtonMenu(, "None", "None", "None", coords);
    }
    const string move2 = playerChar->GetMoves().at(1).name;
    const string move3 = playerChar->GetMoves().at(2).name;
    const string move4 = playerChar->GetMoves().at(3).name;

    return QuadButtonMenu(mvStrs.at(0), mvStrs.at(0), mvStrs.at(0), mvStrs.at(0), coords);
}


Component CombatUI::GetItemButtons(BtnCoords& coords) {
    const string item1 = "Use Medkit";
    const string item2 = "Use StrBuff";
    const string item3 = "Use AgiBuff";
    const string item4 = "Use DefBuff";

    return QuadButtonMenu(item1, item2, item3, item4, coords);
}

Component CombatUI::GetAllButtons(BtnCoords& leftCoords, BtnCoords& rightCoords) {
    return Container::Horizontal({
        GetMoveButtons(leftCoords) | flex | border,
        GetItemButtons(rightCoords) | yflex | border
    });
}

void CombatUI::ShowCombatScreenUntilInput(const vector<wstring>& combatLog) {
  const string mv1 = player->GetM
}
