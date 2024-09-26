# Master Doc - Cayden

## Game Summary 
- PvE (player vs environment)
- Collectible Cards (TCG)
- Based on a combination DnD and Hearthstone
- can compete with other players, just not in real-time

## Nontechnical requirements
- wMana System
- Heroes
- Special Abilities tied to hero archetypes
- Items
- Armour/Weapons
- Spells
- Potential leveling system
- Uses Cards
- Ask Tyler/Chad/Kyle if there’s any more requirements 

## Technical Considerations
- It will use MySQL as a database, as I don’t know any other database languages.
- This will be made in C++ if it’s an exe so it’s faster/smoother, or could use PHP and javascript if web-based, as those are the main languages I am confident in that would apply to this project.
- Potentially may do it from scratch instead of using a platform, as I haven’t had experience with platforms before.
- Although I don’t have experience with micro-services, that could potentially be better for this project, as it can help divide the project into sections easier, as well as be quicker to code and more easily serviceable
- Service-based architecture because it seems to be easier to work with and more simple to learn how to use
- Data structures: deck/cards, heroes, abilities, items, spells, levels (maybe) as those are all requirements for the game that would need data to be stored/playable
- I will probably end up using an API of some sort, as it is more simple to implement if on a time crunch.
- How does tyler/chad/kyle want it to look? Do they have any specific design requirements and if so how do I need to implement them
