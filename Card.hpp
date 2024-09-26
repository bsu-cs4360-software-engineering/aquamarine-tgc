#pragma once

#include "common.hpp"

class Card {
public:
    Card(int i, const std::string& n, const std::string& e);
    void display() const;

    int id;
    std::string name;
    std::string effect;
};
