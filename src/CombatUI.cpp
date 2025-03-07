#include "CombatUI.h"
#include "GridButtons.h"

ftxui::Component CombatUI::MakeButton(const string& text) {
  return ButtonMaker::MakeButton(text, *userInputString, screen);
}


void CombatUI::ShowCombatScreenUntilInput(const vector<wstring>& combatLog) {
  using namespace ftxui;
  // Display the player's move names, or None if they don't have that move yet
  vector<Attack> playerMoves = playerChar->GetMoves();
  vector<string> moveText;
  for(int i = 0; i < 4; i++) {
    if(playerMoves.size() > i) {
      moveText.push_back(playerMoves.at(i).name);
    } else {
      moveText.push_back("None");
    }
  }

  GridButtons moveButtons = GridButtons(moveText[0], moveText[1], moveText[2], moveText[3], userInputString, &screen);
  GridButtons itemButtons = GridButtons("Medkits", "StrBuff", "AgiBuff", "DefBuff", userInputString, &screen);
  Component allButtons = Container::Horizontal({
    moveButtons.btnGrid | xflex | border,
    itemButtons.btnGrid | xflex | border,
    MakeButton("Quit Game") | border | size(HEIGHT, LESS_THAN, 5) | size(WIDTH, LESS_THAN, 20)
  }) | size(WIDTH, LESS_THAN, 110);

  Element info = displayElements.GetAllCombatElements(combatLog);

  Component screenRenderer = Renderer(allButtons, [&]() {
    return vbox({
      displayElements.GetAllCombatElements(combatLog),
      allButtons->Render()
    });
  });

  screen.Loop(screenRenderer);

}
