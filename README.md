# Sparky the Dragon
 Authors: [Roseanne Shildt](https://github.com/roseisanne) [Connor Dickson](https://github.com/TheTaver) [Ayelen Mansilla Soler](https://github.com/a-ms26) [Jared Nepomuceno](http://github.com/Jaredn747)

## Project Description
The player will be able to choose which character’s skill set to use on their quest in turn based combat. The player will go through a series of challenges to stop the dragon from decimating the world.
This project is particularly interesting to us because many of us enjoy playing video games, and we thought it would be exciting to combine our knowledge, experiences, and favorite elements from different games to create one of our own.

### Tools:
- C++
- STL 
- Google Test 
- Git or GitHub
- CMake 
- FTXUI library (https://github.com/ArthurSonzogni/FTXUI) 

### Features: 
- Character creation system with class options, customizable names, and stat distribution
- Turn-based combat system where character stats influence combat abilities and players choose actions each turn
- Inventory system with items and potions for healing, with a stretch goal of adding temporary stat-boosting items
- Leveling system where characters grow stronger as they gain XP, with the potential for a skill tree as a stretch goal
- Storyline-driven progression system where players navigate areas and encounters to complete quests
- Save/load file

### Input/Output:
- FTXUI will be used to display the character’s resources (Health, Items, etc.) and get input for player customization or choices
 
## User Interface Specification
 ### Navigation Diagram
![Diagram drawio](https://github.com/user-attachments/assets/7b2c7ecc-85aa-4469-9f7e-3f0447e8dae9)      
When you start the game, you start at the Main menu where you choose to make a new game / load a game and then from there you go into the game. When you are in the Game, at any point you can quit, so everytime you do you just go to the main menu. In the Game you eventually have to enter combat, so you have a combat screen which ends and goes back to the game when you won your battle. When you die in combat, you go to the game over screen that takes you to the menu. Same thing happens when you win and see the victory screen. 

### Screen Layouts
![Screen_Layout1](https://github.com/user-attachments/assets/7046bfd9-11e2-46c9-8171-3b001deb7fa4)
![Screen_Layout2](https://github.com/user-attachments/assets/89da2b96-0b79-403d-9f1e-7a89261b0ac0)

Main menu screen 
\- Allows the player to continue a save (if one exists), start a new game, or exit the game    
\- Purpose: player can create a new game or load into a game        
In-game screen     
\- Room description text, item options, buttons for player choices (what choices player can do when given)     
\- Purpose: Text of current room so player knows what room they’re in and what they can do in the room, item options so they know what items they have and how many, box for user to choose an option (user input), output will be new room description or event (process repeats)           
Battle screen     
\- Descriptive text explaining what you did and what enemy did, options for attacks, shows your characters hp and enemies hp, options to choose different attacks, item options    
\- so that player knows that their move went through and also knows what attacks enemy did, hp displays so that player knows how low they are and how low enemy is, options for attacks so player can choose what attack to use, item options so they can use an item instead of attack        
Game over screen     
\- Displaying that the game is over, option to quit game     
\- Purpose: Return to main menu after dying         
Victory screen    
\- Displays you won game, button to quit game or return to main menu   
\- to go back to menu when you completed the game   



## Class Diagram
![uml diagram](https://github.com/user-attachments/assets/08fcc5f3-8df7-4a0b-8366-957b831b6a09)

### Class Descriptions:
#### View Classes:
\- Menu Display Class: I/O class for displaying the start and game over menus, returns a string describing the player’s input on that screen (whether to start a new game or continue a save, or quit)
\- Room Display Class: Displays UI for room description, along with the player’s current stats/items. A function that describes the room and the choice the player can make in that room returns a string description of the choice they made.
\- Combat Display Class: Describes the current opponent, and the displays the player’s options for actions to take in battle, and gets input for their choices

#### Controller Classes:
\- Game Controller Class: Manages overall game flow, including saving/loading game data from files, starting and maintaining the main game loop, of transitioning between rooms, updating the player’s position, and starting the events of that room, starting combat, and ending the game
\- Combat Controller Class: Manage in-combat game loop, tracks combatants’ current hp, ending combat when one dies, gets each combatant’s next attack, and executing the attacks/actions each round

#### Entity Classes:
\- Character class: Interface for player characters as well as enemy combatants. Has member variables for the character’s stats (Strength, Defense, Agility, Max/Current Health, Level) and a vector of possible moves that the character can perform during combat that differs based on the type of character.
\- Player Interface: Brawler/Shooter/Duelist: Different options for classes the player can choose from, each with a unique moveset implementation and starting stat distribution. Also has member variables (int vectors) to track the current items the player is carrying and can use, and the maximum amount of each they can carry. CanLevelUp() function returns whether the player has enough xp to level up, in which case the GameController will display the level up menu, and call the LevelUp() function with the stats the player chooses to increase, which will increase those stats. The GetItem() function adds an item to the player’s inventory, returning true if it was successful, or false if it failed (inventory was full, so couldn’t add it). The UseItem() function removes an item from their inventory, if they have more than 0, and the ItemCount() function returns how many of an item type they have.
\- NPC Interface: Is the base class for all NPCs/Enemies, each of which will have their own implementation of the GetAttack() function. They will also each have member variables for the exp reward and item rewards the player gets from defeating them in battle.
\- Enemy type Subclasses: Derived from the NPC interface, the GetAttack() function will pick what attack to use in battle, so enemies at different points in the game have different AI for battle decisions.
\- Attack Class: Member variables for the attack’s base accuracy, name of the attack, number of uses the attack has, and the attack’s base damage. The DoesItHit() function decides whether the attack hits or not, based on the attack’s accuracy, and the agility of the target, with rng seeded by the seed passed to the function. The hit() function takes in the attacker and the target of the attack (and the seed for randomness calculations) and calls the private DoesItHit() function, and if it hits, deals damage scaled by the attacker’s strength to the target. If the attack has a nonzero effect chance, Hit will also call the private ApplyEffect() function, again with the rng seed, which decides whether to apply the effect or not, decreasing one of the target’s stats (determined by the effectStat member variable) if successful.
\- Room Class: Constructor will require a filename to load the room’s info from. Will contain a room’s description, and a choice that the player can make in that room. Member variable hasCombat will be a boolean value that describes whether a combat encounter should start when the player enters that room, which the GameController will load as the player enters. GetNumOptions() returns how many options the player can pick between for that room’s choice, with GetOptions() returning text to describe the options themselves.

 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
