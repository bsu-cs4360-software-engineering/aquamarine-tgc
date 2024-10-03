#include "catch.hpp"
#include "game.hpp"

TEST_CASE("Game class tests", "[game]") {
    Game game("cardData.json");

    SECTION("Initial game state") {
        REQUIRE(game.getDeckSize() == 12);
    }

    SECTION("Draw card") {
        size_t initialHandSize = game.getHandSize();
        game.drawCard();
        REQUIRE(game.getHandSize() == initialHandSize + 1);
    }

    SECTION("Play card") {
        game.drawCard();
        size_t initialHandSize = game.getHandSize();
        game.playCard(0);  // Play the first card in hand
        REQUIRE(game.getHandSize() == initialHandSize - 1);
    }

    SECTION("Get valid input") {
        int input = game.getValidInput(1, 4);
        REQUIRE(input >= 1);
        REQUIRE(input <= 4);
    }
}