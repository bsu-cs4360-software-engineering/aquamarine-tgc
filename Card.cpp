#include "card.hpp"

Card::Card(int i, const std::string& n, const std::string& e) : id(i), name(n), effect(e) {}

void Card::display() const {
    std::cout << "ID: " << id << " | " << name << " | Effect: " << effect << std::endl;
}

bool Card::operator==(const Card& other) const {
    return id == other.id && name == other.name && effect == other.effect;
}

bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}