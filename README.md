# Hearthstone/DnD - Master Doc and README
### Team Aquamarine

## Description
The game should be a mixture of Hearthstone, a turn based card game, and Dnd, a story telling game involving role play, combat, and skills.

## Installation
1. Clone repository to run project locally
2. Check that g++ is installed and running with the terminal command ```g++ --version```   

## Usage  
1. Verify that user is in the project directory in terminal (aquamarine-tgc)  
2. Compile the project locally by running the terminal command ```g++ -std=c++11 Main.cpp Game.cpp Deck.cpp Card.cpp -o card_game```  
3. Run the terminal command ```./card_game``` to run the program locally  
4. follow the prompts from within the terminal  

## Summary
The game should be a mixture of Hearthstone and Dnd. Hearthstone is a turn-based card game between 2 people. Each player has a deck of 30 cards and a special hero that has a special power. The goal is to beat the opponent's hero, and mana crystals are used by each player to use abilities or minions. Dnd has a similar premise, but uses more of a storytelling format. Multiple players each choose a character to play in the game to exist within the world. The game is moderated by the Dungeon Master (DM) who works on creating the story. Multi-sided dice are rolled by the player to determine if their desired actions were successful. The 3 main components of Dnd are role-play, combat, and skills. 

This Trading Card Game is made to be a card game equivalent to the Role-Playing game, Dungeons and Dragons, on a virtual platform. Players will build a deck of virtual cards based around heroes, their characters, full of abilities, equipment/items, and spells that they will use cooperatively to fight monsters to earn gold (in-game currency) to purchase more cards. Each hero will have their own class, like their DnD counterparts, that will have special mechanics based on their class. 

### Card Specifics
•	Wizards - able to generate extra mana to dedicate to spell slots that will be used to spells specific to the class. Wizard spell slots carry over from one turn to the next.  
•	Fighters – Able to play action surge cards that allow them another turn after their current turn.  
•	Barbarians – able to play rage cards that allow damage dealt to them to be ignored until their next turn.  
•	Bard – Able to play inspiration cards that function as another resource for special bard-only spells that can buff allies and debuff enemies.  
•	Paladin – Able to play smite cards that can be used to boost damage or play the card “Lay on Hands” to heal one ally or revive a fallen ally.  
•	Cleric – Able to play faith cards that allow them to gain faith as another resource for cleric specific healing spells  
•	Druid – Able to play transformation cards to turn into various animals.  
•	Ranger – Able to play companion cards which summons animal companions to provide assistance in the form of buffs  
•	Rogue – Able to play sneak cards which gives Rogue critical damage on enemies for the duration of their turn  
•	Warlock – Has the “Eldritch blast” card that can be modified with Patron cards.  
•	Sorcerer – able to generate extra mana for card play and purchase spell slots like the Wizard, but their slots are only available for the turn on which they are purchased.  
•	Artificer – Able to play special artifact cards that can be combined together to modify their capabilities.  
•	Monk – Able to play Chi cards that generate Chi points which can be used to multiply the number of attacks a monk can perform in a single turn  

## Functional Requirements
•	Allow the player to choose a class  
•	Give the player enough card at the beginning to build a deck for any class.  
•	Allow the player to build their own decks  
•	Only display cards in the deck builder that is playable for the chosen class  
•	Allow the player to save custom decks  
•	Join new games with other players  
•	Continue games with friends/party members from previous games  
•	Allow players to fight monsters for coins (possibly even item cards as loot)  
•	Create procedurally generated dungeons for players to fight monsters in. With each room being a battle  
•	Players should be able to draw cards from their deck and place it into their hand  
•	Split a turn into several stages it guides new players through  
•	Allow players to play a card from their hand, so long as it meets the requirements to be played  
•	Be able to save user data on the player’s device, with an online backup on our servers.  
•	Allow players to purchase card packs for coins (possibly have special packs that cost real world money… not preferred. Ask the guys at EA how lootboxes went.)  
•	Allow player to exit the game when they have finished playing  

## Technical Considerations:
Database: Local Json file

Platform: Web Application

Language: C++

Mono-repo vs. Micro-service: mono-repo

Service-based vs. Event-based: service-based

Data-structures: Document based database, data will be sent/recived in Json

API vs. Local service: Local service when possible
