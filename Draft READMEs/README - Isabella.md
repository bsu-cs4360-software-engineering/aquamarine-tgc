# Game Card Game Master Doc - Isabella

### Summary:
The game should be a mixture of Hearthstone and Dnd. Hearthstone is a turn-based card game between 2 people. Each player has a deck of 30 cards and a special hero that has a special power. The goal is to beat the opponent's hero, and mana crystals are used by each player to use abilities or minions. Dnd has a similar premise, but uses more of a storytelling format. Multiple players each choose a character to play in the game to exist within the world. The game is moderated by the Dungeon Master (DM) who works on creating the story. Multi-sided dice are rolled by the player to determine if their desired actions were successful. The 3 main components of Dnd are role-play, combat, and skills. 



The game is moderated by the DM, who is a non-playable character who guides the story and plot

The game has a Player vs. Environment (PvE) focus with players individually collect cards to build their decks against computer opponents

Hero archetypes have specific abilities and mana tied to them

Player is able to use armor to increase mana

Cards consist of either a special ability, item, amor to increase mana, weapons to harm the opponent, or spells to do either after

Each player works through a predetermined story guided by the DM

Player will encounter opponents who will will need to be defeated by playing cards

Game is completed after the player defeats the final boss with cards

## Non-Technical Functional Requirements:
Each player should play the game with a deck of cards of a designated size (30)

Player is able to place a card from their deck and use the action listed

After playing a card, the player rolls a dice, in which the number rolled determines the amount of activity that the card does

For example: a damage card, rolled a 2, means that the attack will not be very harmful

Opponents health is depleted with attacks from the player, but can also cause player health to go down through their own attacks

Player and opponent attacks go back and forth playing turns until one is defeated

Player encounters multiple opponents throughout the game

## Technical Considerations:
Database: Cloud Database, SQL database because that is what I have the most knowledge working with, but open to change depending on project specifications.

Platform: Web Application, as specified by the PO.

Language: either C++ or Java, as they are some of the most common languages for video games to be written in, as the game software is demanding.

Mono-repo vs. Microservice: Mono-repo, because then I don’t have to use API calls to get code from outside my repository, and everything can just be within my central repo. 

Service-based vs. Event-based: Service-based, because I am the most familiar with it from my personal and work projects.

Data-structures: Card data will be stored as an object with parameters depending on the card, such as health, mana, attack damage, etc. Data will be sent and received in Json.

API vs. Local service: Local service to decrease outside dependencies. 


