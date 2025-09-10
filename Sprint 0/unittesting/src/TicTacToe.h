#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.h"
#include "Player.h"
#include "IGameIO.h"

class TicTacToe {
private:
   Board board;
   Player players[2];
   int currentPlayerIndex;
   IGameIO& io;

   void drawBoard() const;
   void promptMove(int& row, int& col);

public:
   explicit TicTacToe(IGameIO& ioHandler);
   Player& getCurrentPlayer();
   void switchTurn();
   void play();
};

#endif