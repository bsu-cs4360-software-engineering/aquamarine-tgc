#include "deck.hpp"

void Deck::loadFromJson(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }
    json j;
    file >> j;

    for (const auto& card : j["cards"]) {
        cards.emplace_back(card["id"], card["name"], card["effect"]);
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard() {
    if (cards.empty()) {
        throw std::runtime_error("Deck is empty");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}

size_t Deck::size() const {
    return cards.size();
}
