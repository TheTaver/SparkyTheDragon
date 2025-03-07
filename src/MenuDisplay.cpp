#include "MenuDisplay.h"

ButtonOption Style()  {
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

string MenuDisplay::Displaystart() const{
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
                buttons->Render() | flex,
            }) | flex | border;
    });

    screen.Loop(renderer);
    return playerInput;
  };

Element MenuDisplay::GetClassDescritption(){
  auto textBox = vbox({
    text(L"Brawler class has the most defence stats, less damage intake.") | flex,
    separator(),
    text(L"Shooter class has the most strength stats, alot of damage output.") | flex,
    separator(),
    text(L"Duelist class has the most agility stats, higher chance to dodge attacks.") | flex,
  });

  return window(text(L" Description ") | center, textBox) |align_right;
};

string MenuDisplay::DisplayClassSelection() const{
  string playerInput = "";
  MenuDisplay menu;
  Element Description = menu.GetClassDescritption();
  auto screen = ScreenInteractive::FitComponent();

  auto brawlerb = Button("Brawler", [&] { playerInput = "Brawler"; screen.ExitLoopClosure()(); }, Style());
  auto shooterb = Button("Shooter", [&] { playerInput = "Shooter"; screen.ExitLoopClosure()(); }, Style()); 
  auto duelistb = Button("Duelist", [&] { playerInput = "Duelist"; screen.ExitLoopClosure()(); }, Style());
 
  // The tree of components. This defines how to navigate using the keyboard.
  // The selected `row` is shared to get a grid layout.
  int row = 0;
  auto buttons = Container::Vertical({
    brawlerb | flex,
    shooterb | flex,
    duelistb | flex
  });

  auto classOptions = Renderer(buttons, [&] {
    return vbox({
      text("Pick your class!") | center | bold,
      separator(),
      buttons->Render() | flex,
      Description,
  }) | flex | border;
  });

    // auto DescriptionandOptionsTogether = Renderer(buttons, [&]{
    //   return hbox({
    //     Description,
    //   });
    // });

    //screen.Loop(DescriptionandOptionsTogether);
    screen.Loop(classOptions);
    return playerInput;
  };

string MenuDisplay::DisplayGameOver() const{
    //display game over 
    //have option to quit game or continue from last save (2 options)
    string playerInput = "";
    auto screen = ScreenInteractive::FitComponent();

    auto quitgameb = Button("Quit Game", [&] { playerInput = "Quitcuzdead"; screen.ExitLoopClosure()(); }, Style());
    auto contlastsaveb = Button("Load Checkpoint", [&] { playerInput = "Returncd"; screen.ExitLoopClosure()(); }, Style()); 
 
    int row = 0;
    auto buttons = Container::Vertical({ 
      contlastsaveb | flex,
      quitgameb | flex
    });
 
    auto renderer = Renderer(buttons, [&] {
      return vbox({
                text("GAME OVER") | center | bold,
                separator(),
                buttons->Render() | flex,
            }) | flex | border;
    });
    screen.Loop(renderer);
    return playerInput;
  };

string MenuDisplay::DisplayVictory() const{
  string playerInput = "";
  auto screen = ScreenInteractive::FitComponent();

  auto playagainb = Button("Play Again", [&] { playerInput = "Again"; screen.ExitLoopClosure()(); }, Style()); 
  auto quitfrfrb = Button("Quit Game", [&] { playerInput = "Quit"; screen.ExitLoopClosure()(); }, Style());
  

  int row = 0;
  auto buttons = Container::Vertical({ 
    playagainb | flex,
    quitfrfrb | flex
  });

  auto renderer = Renderer(buttons, [&] {
    return vbox({
              text("VICTORY!") | center | bold,
              separator(),
              buttons->Render() | flex,
          }) | flex | border;
  });
  screen.Loop(renderer);
  return playerInput;
};