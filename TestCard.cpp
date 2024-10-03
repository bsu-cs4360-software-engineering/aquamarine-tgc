#include "catch.hpp"
#include "card.hpp"
#include <sstream>
#include <iostream>

TEST_CASE("Card creation and comparison", "[card]") {
    Card card1(1, "Test Card", "Test Effect");
    Card card2(1, "Test Card", "Test Effect");
    Card card3(2, "Another Card", "Another Effect");

    SECTION("Cards with same data are equal") {
        REQUIRE(card1 == card2);
    }

    SECTION("Cards with different data are not equal") {
        REQUIRE(card1 != card3);
    }
}

TEST_CASE("Card display", "[card]") {
    Card card(1, "Test Card", "Test Effect");
    std::stringstream ss;
    auto old_buf = std::cout.rdbuf(ss.rdbuf());
    
    card.display();
    std::cout.rdbuf(old_buf);

    REQUIRE(ss.str() == "ID: 1 | Test Card | Effect: Test Effect\n");
}