
// Make buttons fill in background & bold name when hovered/selected
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
    
  // Returns component for the quit button
  Component screenQuitButton(string& quitStr, ScreenInteractive& screen) {
    return Button("Quit Game", [&] { quitStr = "Quit"; screen.ExitLoopClosure()(); }, Style());;
  }
  
  // Doesn't work
  void fullSidebarRenderer(const Character& player, const vector<int>& currItems, const vector<int>& maxItems, string& quitStr, ScreenInteractive& screen) {
    Element infoSidebar = GetPlayerSidebar(player, currItems, maxItems);
    Component quitButton = screenQuitButton(quitStr, screen);
    Component sidebarRenderer = Renderer(quitButton, [&] {
      return vbox({
        infoSidebar | yflex,
        quitButton->Render()
      });
    });
    screen.Loop(sidebarRenderer);
  } 
  
  
  