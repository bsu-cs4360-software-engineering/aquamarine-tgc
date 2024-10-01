#pragma once

#include "common.hpp"
using namespace std;

class Card {
public:
    Card(int i, const string& n, const string& e);
    void display() const;

    int id;
    string name;
    string effect;
};
