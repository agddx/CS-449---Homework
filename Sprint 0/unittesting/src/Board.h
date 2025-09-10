#ifndef BOARD_H
#define BOARD_H
class Board {
private:
    char grid[3][3];
    int filledCells;
public:
    Board();
    bool isValidMove(int row, int col) const;
    void makeMove(int row, int col, char symbol);
    bool checkWin(char symbol) const;
    bool isFull() const;
    int getFilledCellsCount() const;
    char getCell(int row, int col) const;
};
#endif