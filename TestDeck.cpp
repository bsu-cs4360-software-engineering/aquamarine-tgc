#include "catch.hpp"
#include "deck.hpp"

TEST_CASE("Deck class tests", "[deck]") {
    Deck deck;

    SECTION("Load from JSON") {
        REQUIRE_NOTHROW(deck.loadFromJson("cardData.json"));
        REQUIRE(deck.size() == 12);
    }

    SECTION("Draw card") {
        deck.loadFromJson("cardData.json");
        size_t initialSize = deck.size();
        REQUIRE_NOTHROW(deck.drawCard());
        REQUIRE(deck.size() == initialSize - 1);
    }

    SECTION("Draw from empty deck") {
        REQUIRE_THROWS_AS(deck.drawCard(), std::runtime_error);
    }

    SECTION("Shuffle deck") {
        deck.loadFromJson("cardData.json");
        std::vector<Card> originalOrder;
        while (deck.size() > 0) {
            originalOrder.push_back(deck.drawCard());
        }

        deck.loadFromJson("cardData.json");
        deck.shuffle();

        std::vector<Card> shuffledOrder;
        while (deck.size() > 0) {
            shuffledOrder.push_back(deck.drawCard());
        }

        REQUIRE(originalOrder.size() == shuffledOrder.size());
        REQUIRE_FALSE(originalOrder == shuffledOrder);
    }
}