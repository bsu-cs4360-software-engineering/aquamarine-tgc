#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "deck.hpp"
#include "common.hpp"

using json = json;

TEST_CASE("Deck::loadFromJson", "[loadFromJson]") {
    Deck deck;
    std::ofstream file("test_deck1.json");
    file << R"({
        "cards": [
            {"id": 1, "name": "Card1", "effect": "Effect1"},
            {"id": 2, "name": "Card2", "effect": "Effect2"},
            {"id": 3, "name": "Card3", "effect": "Effect3"}
        ]
    })";
    file.close();

    deck.loadFromJson("test_deck1.json");
    REQUIRE(deck.size() == 3);
}

TEST_CASE("Deck::shuffle", "[shuffle]") {
    Deck deck;
    std::ofstream file("test_deck.json");
    file << R"({
        "cards": [
            {"id": 1, "name": "Card1", "effect": "Effect1"},
            {"id": 2, "name": "Card2", "effect": "Effect2"},
            {"id": 3, "name": "Card3", "effect": "Effect3"}
        ]
    })";
    file.close();

    deck.loadFromJson("test_deck.json");

    // Directly access the cards vector for comparison
    std::vector<Card> original_cards = deck.cards;
    deck.shuffle();
    std::vector<Card> shuffled_cards = deck.cards;

    // Check that the order is different
    bool is_different = false;
    for (size_t i = 0; i < original_cards.size(); ++i) {
        if (original_cards[i].id != shuffled_cards[i].id) {
            is_different = true;
            break;
        }
    }
    REQUIRE(is_different);
}

TEST_CASE("Deck::drawCard", "[drawCard]") {
    Deck deck;
    std::ofstream file("test_deck.json");
    file << R"({
        "cards": [
            {"id": 1, "name": "Card1", "effect": "Effect1"},
            {"id": 2, "name": "Card2", "effect": "Effect2"},
            {"id": 3, "name": "Card3", "effect": "Effect3"}
        ]
    })";
    file.close();

    deck.loadFromJson("test_deck.json");
    size_t initial_size = deck.size();
    Card card = deck.drawCard();
    REQUIRE(deck.size() == initial_size - 1);
    REQUIRE(card.name == "Card3"); // Assuming the last card in the JSON file is "Card3"
    REQUIRE(card.effect == "Effect3"); // Assuming the last card in the JSON file has effect "Effect3"
}

TEST_CASE("Deck::size", "[size]") {
    Deck deck;
    std::ofstream file("test_deck.json");
    file << R"({
        "cards": [
            {"id": 1, "name": "Card1", "effect": "Effect1"},
            {"id": 2, "name": "Card2", "effect": "Effect2"},
            {"id": 3, "name": "Card3", "effect": "Effect3"}
        ]
    })";
    file.close();

    deck.loadFromJson("test_deck.json");
    REQUIRE(deck.size() == 3);
}
