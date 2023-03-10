#include<iostream>
#include"board.h"


int main(void)
{
  std::cout << "Welcome to TTT game!\n";
  std::cout << "Choose board size:" << '\n';
  
  uint32_t boardSize = 0;
  uint32_t x = 0, y = 0;
  
  std::cin >> boardSize;
  game::Board board = game::Board(boardSize,'/');

  while (board.ifRunning()) {
    
    std::cout << board;
    std::cout << "Movements left: " << board.getMovementsLeft() << '\n';
    std::cout << "Row: "; 
    std::cin >> x;
    std::cout << "Column: ";
    std::cin >> y;

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