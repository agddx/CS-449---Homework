#include <gtest/gtest.h>
#include "../src/IGameIO.h"
#include "../src/TicTacToe.h"
#include <algorithm>

class MockIO : public IGameIO {
public:
    std::vector<std::string> outputs;
    std::vector<int> inputs;
    size_t inputIndex = 0;
    void print(const std::string& msg) override { outputs.push_back(msg); }
    void println(const std::string& msg) override { outputs.push_back(msg + "\n"); }
    void readInt(int& value) override {
        if (inputIndex < inputs.size()) value = inputs[inputIndex++];
        else value = 1;
    }
};

TEST(TicTacToeTest, SimulatedGameDraw) {
    MockIO io;
    io.inputs = {
        1,1, 1,2, 1,3,
        2,1, 2,3, 2,2,
        3,1, 3,3, 3,2
    };

    TicTacToe game(io);
    game.play();

    bool found = std::any_of(io.outputs.begin(), io.outputs.end(), [](const std::string& s){
        return s.find("It's a draw!") != std::string::npos;
    });
    EXPECT_TRUE(found);
}

TEST(TicTacToeTest, PlayerXWinsTopRow) {
    MockIO io;

    io.inputs = {
        1,1,
        2,1,
        1,2,
        2,2,
        1,3
    };

    TicTacToe game(io);
    game.play();

    auto it = std::find_if(io.outputs.begin(), io.outputs.end(), [](const std::string& line) {
        return line.find("Player X wins!") != std::string::npos;
    });

    EXPECT_NE(it, io.outputs.end());
}
