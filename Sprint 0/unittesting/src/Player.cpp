#include "Player.h"

Player::Player(char sym, std::string n)
    : symbol(sym), name(std::move(n)) {}

char Player::getSymbol() const { return symbol; }
std::string Player::getName() const { return name; }