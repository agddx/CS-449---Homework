#include "TicTacToe.h"
#include "IGameIO.h"
#include <iostream>

class ConsoleIO : public IGameIO {
public:
    void print(const std::string& msg) override { std::cout << msg; }
    void println(const std::string& msg) override { std::cout << msg << std::endl; }
    void readInt(int& value) override { std::cin >> value; }
};

int main() {
    ConsoleIO io;
    TicTacToe game(io);
    game.play();
    return 0;
}
