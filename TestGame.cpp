#include "catch.hpp"
#include "game.hpp"
#include <sstream>

TEST_CASE("Game initialization", "[game]") {
    REQUIRE_NOTHROW(Game("cardData.json"));
}

TEST_CASE("Game basic operations", "[game]") {
    Game game("cardData.json");

    SECTION("Initial deck size") {
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
        REQUIRE_NOTHROW(game.playCard(0));
        REQUIRE(game.getHandSize() == initialHandSize - 1);
    }
}