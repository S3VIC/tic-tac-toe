#include<iostream>
#include"board.h"


int main(void)
{
  game::displayWelcomeMessage();
  
  uint32_t boardSize = 0;
  uint32_t x = 0, y = 0, boardWidth = 0, boardHeight = 0;

  boardWidth = game::getBoardWidth();
  boardHeight = game::getBoardHeight();

  game::Board board = game::Board(boardWidth, boardHeight,'/');

  while (board.ifRunning()) {
    
    game::displayStatusAndDefineMove(&x, &y, board);

    if (board.checkMove(x, y))
      board.move(x, y);
    else {
      game::clearTerminal();
      std::cout << "Move not valid. Try again." << '\n';
    }
    board.checkMovementsLeft();
  }

  std::cout << "Game finished!" << '\n';
  return 0;
}