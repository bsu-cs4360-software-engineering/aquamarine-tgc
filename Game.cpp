#include "game.hpp"

   Game::Game(const std::string& deckFile) : playerTurn(true) {
       try {
           deck.loadFromJson(deckFile);
           deck.shuffle();
       } catch (const std::exception& e) {
           std::cerr << "Error initializing game: " << e.what() << std::endl;
           exit(1);
       }
   }

   bool Game::drawCard() {
       if (deck.size() > 0) {
           if (playerTurn) {
               playerHand.push_back(deck.drawCard());
           } else {
               computerHand.push_back(deck.drawCard());
           }
           return true;
       }
       return false;
   }

   void Game::playCard(size_t index) {
       if (playerTurn && index < playerHand.size()) {
           field.push_back(playerHand[index]);
           playerHand.erase(playerHand.begin() + index);
       }
   }

   void Game::endTurn() {
       playerTurn = !playerTurn;
       if (!playerTurn) {
           computerTurn();
       }
   }

   bool Game::isPlayerTurn() const {
       return playerTurn;
   }

   size_t Game::getDeckSize() const {
       return deck.size();
   }

   int Game::getHandSize() const {
        return playerTurn ? playerHand.size() : computerHand.size();
    }

   const std::vector<Card>& Game::getField() const {
       return field;
   }

   void Game::computerTurn() {
       // Simple AI: draw a card and play a random card if possible
       drawCard();
       if (!computerHand.empty()) {
           size_t randomIndex = rand() % computerHand.size();
           field.push_back(computerHand[randomIndex]);
           computerHand.erase(computerHand.begin() + randomIndex);
       }
       endTurn();
   }