#pragma once

#include "common.hpp"
#include "deck.hpp"

class Game {
public:
    Game(const std::string& deckFile);
    void start();
    int getValidInput(int min, int max) const;
    void playCard(size_t index);
    void drawCard();
    void displayHand() const;
    
    size_t getDeckSize() const;
    size_t getHandSize() const;

private:
    void displayMenu() const;
    
    Deck deck;
    std::vector<Card> hand;
};
