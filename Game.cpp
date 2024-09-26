#include "game.hpp"

Game::Game(const std::string& deckFile) {
    try {
        deck.loadFromJson(deckFile);
        deck.shuffle();
    } catch (const std::exception& e) {
        std::cerr << "Error initializing game: " << e.what() << std::endl;
        exit(1);
    }
}

void Game::start() {
    std::cout << "Hearthstone/DnD Game" << std::endl;
    std::cout << "Deck loaded with " << deck.size() << " cards." << std::endl;
    
    while (true) {
        displayMenu();
        int choice = getValidInput(1, 4);

        switch (choice) {
            case 1:
                drawCard();
                break;
            case 2:
                playCard();
                break;
            case 3:
                displayHand();
                break;
            case 4:
                std::cout << "Thanks for playing!" << std::endl;
                return;
        }
    }
}

void Game::displayMenu() const {
    std::cout << "\n=== Menu ===" << std::endl;
    std::cout << "1. Draw a card" << std::endl;
    std::cout << "2. Play a card" << std::endl;
    std::cout << "3. Display hand" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "Enter your choice (1-4): ";
}

int Game::getValidInput(int min, int max) const {
    int choice;
    while (true) {
        if (std::cin >> choice && choice >= min && choice <= max) {
            return choice;
        } else {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Game::drawCard() {
    try {
        hand.push_back(deck.drawCard());
        std::cout << "You drew: ";
        hand.back().display();
        std::cout << "Cards left in deck: " << deck.size() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

void Game::playCard() {
    if (hand.empty()) {
        std::cout << "Your hand is empty. Draw a card first." << std::endl;
        return;
    }

    displayHand();
    std::cout << "Enter the index of the card you want to play (0-" << hand.size() - 1 << "): ";
    int index = getValidInput(0, hand.size() - 1);

    std::cout << "You played: ";
    hand[index].display();
    std::cout << "Card effect activated: " << hand[index].effect << std::endl;
    hand.erase(hand.begin() + index);
}

void Game::displayHand() const {
    if (hand.empty()) {
        std::cout << "Your hand is empty." << std::endl;
        return;
    }
    std::cout << "Your hand:" << std::endl;
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << i << ": ";
        hand[i].display();
    }
}
