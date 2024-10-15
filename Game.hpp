// game.hpp
   #pragma once

   #include "common.hpp"
   #include "deck.hpp"

   class Game {
   public:
       Game(const std::string& deckFile);
       bool drawCard();
       void playCard(size_t index);
       void endTurn();
       bool isPlayerTurn() const;
       
       size_t getDeckSize() const;
       int getHandSize() const;
       const std::vector<Card>& getHand() const;
       const std::vector<Card>& getField() const;

   private:
       void computerTurn();
       
       Deck deck;
       std::vector<Card> playerHand;
       std::vector<Card> computerHand;
       std::vector<Card> field;
       bool playerTurn;
   };