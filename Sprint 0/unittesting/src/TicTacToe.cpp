#include "TicTacToe.h"
#include <sstream>

TicTacToe::TicTacToe(IGameIO& ioHandler)
   : currentPlayerIndex(0), io(ioHandler) {
    players[0] = Player('X', "Player X");
    players[1] = Player('O', "Player O");
}

Player& TicTacToe::getCurrentPlayer() {
    return players[currentPlayerIndex];
}

void TicTacToe::switchTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

void TicTacToe::drawBoard() const {
    io.println("-------------");
    for (int i = 0; i < 3; i++) {
        std::ostringstream row;
        row << "| ";
        for (int j = 0; j < 3; j++) {
            row << board.getCell(i, j) << " | ";
        }
        io.println(row.str());
        io.println("-------------");
    }
}

void TicTacToe::promptMove(int& row, int& col) {
    while (true) {
        std::ostringstream prompt;
        prompt << getCurrentPlayer().getName() << " (" << getCurrentPlayer().getSymbol()
               << "), enter row (1‑3) and column (1‑3): ";
        io.print(prompt.str());
        io.readInt(row);
        io.readInt(col);
        row--; col--;
        if (board.isValidMove(row, col)) break;
        io.println("Invalid move. Try again.");
    }
}

void TicTacToe::play() {
    io.println("Welcome to Tic‑Tac‑Toe!");
    while (!board.isFull()) {
        drawBoard();
        int row, col;
        promptMove(row, col);
        board.makeMove(row, col, getCurrentPlayer().getSymbol());
        if (board.checkWin(getCurrentPlayer().getSymbol())) {
            drawBoard();
            io.println(getCurrentPlayer().getName() + " wins!");
            return;
        }
        switchTurn();
    }
    drawBoard();
    io.println("It's a draw!");
}