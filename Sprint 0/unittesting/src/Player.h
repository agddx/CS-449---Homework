#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private:
    char symbol;
    std::string name;
public:
    Player(char sym = 'X', std::string n = "Player X");
    char getSymbol() const;
    std::string getName() const;
};
#endif