#include "MenuDisplay.h"

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

string MenuDisplay::DisplayClassSelection() const{
    string playerInput = "";
    auto screen = ScreenInteractive::FitComponent();

    auto brawlerb = Button("Brawler", [&] { playerInput = "Brawler"; screen.ExitLoopClosure()(); }, Style());
    auto shooterb = Button("Shooter", [&] { playerInput = "Shooter"; screen.ExitLoopClosure()(); }, Style()); 
    auto fighterb = Button("Fighter", [&] { playerInput = "Fighter"; screen.ExitLoopClosure()(); }, Style());
 
    // The tree of components. This defines how to navigate using the keyboard.
    // The selected `row` is shared to get a grid layout.
    int row = 0;
    auto buttons = Container::Vertical({
      brawlerb | flex,
      shooterb | flex,
      fighterb | flex
    });

    //discription of classes
    auto textBox = vbox({
      text(L"Description") | flex | bold,
      separator(),
      text(L"Brawler class has the most defence stats, less damage intake.") | flex,
      separator(),
      text(L"Shooter class has the most strength stats, alot of damage output.") | flex,
      separator(),
      text(L"Fighter class has the most agility stats, higher chance to dodge attacks.") | flex,
    }) | border;

    auto classAndDescriptionTogether = Renderer(buttons, [&] {
        return hbox({
          vbox({
            text("Pick your class!") | center | bold,
                separator(),
                buttons->Render() | flex,
          }),
          textBox | flex,
        }) | flex |border;
    });

    screen.Loop(classAndDescriptionTogether);
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