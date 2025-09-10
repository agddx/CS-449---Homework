#include "Board.h"

Board::Board() : filledCells(0) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            grid[i][j] = ' ';
}

bool Board::isValidMove(int row, int col) const {
    return row>=0 && row<3 && col>=0 && col<3 && grid[row][col]==' ';
}

void Board::makeMove(int row, int col, char symbol) {
    if (isValidMove(row, col)) {
        grid[row][col] = symbol;
        filledCells++;
    }
}

bool Board::checkWin(char symbol) const {
    for (int i = 0; i < 3; ++i)
        if (grid[i][0]==symbol && grid[i][1]==symbol && grid[i][2]==symbol) return true;
    for (int i = 0; i < 3; ++i)
        if (grid[0][i]==symbol && grid[1][i]==symbol && grid[2][i]==symbol) return true;
    if (grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol) return true;
    if (grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol) return true;
    return false;
}

bool Board::isFull() const { return filledCells == 9; }
int Board::getFilledCellsCount() const { return filledCells; }
char Board::getCell(int row, int col) const { return grid[row][col]; }