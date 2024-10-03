#pragma once
#include "common.hpp"

class Card {
public:
    Card(int i, const std::string& n, const std::string& e);
    void display() const;
    
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;

    int id;
    std::string name;
    std::string effect;
};
