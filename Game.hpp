#pragma once

#include "common.hpp"
#include "deck.hpp"

class Game {
public:
    Game(const std::string& deckFile);
    void start();

private:
    void displayMenu() const;
    int getValidInput(int min, int max) const;
    void drawCard();
    void playCard();
    void displayHand() const;

    Deck deck;
    std::vector<Card> hand;
};

