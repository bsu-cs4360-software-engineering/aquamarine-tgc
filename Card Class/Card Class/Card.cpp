#include "card.hpp"

Card::Card(int i, const std::string& n, const std::string& e) : id(i), name(n), effect(e) {}

void Card::display() const {
    std::cout << "ID: " << id << " | " << name << " | Effect: " << effect << std::endl;
}