#pragma once

#include "common.hpp"
#include "card.hpp"

class Deck {
public:
    void loadFromJson(const std::string& filename);
    void shuffle();
    Card drawCard();
    size_t size() const;
    std::vector<Card> cards;
    private:
};