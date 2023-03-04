#include<iostream>
#include"board.h"


int main(void)
{
  game::Board board = game::Board(8,'/');
  int x = 0, y = 0;
  std::cout << board;
  while (board.ifRunning()) {
    std::cin >> x >> y;
    if (board.checkMove(x, y))
      board.move(x, y);
    else {
      game::clearTerminal();
      std::cout << "Move not valid. Try again." << '\n';
    }
    std::cout << board;
    
  }
  return 0;
}

void wykonajRuch(int x, int y, char tab[17][17]){
      if(tab[2*x-1][2*y-1] == (char)88) tab[2*x-1][2*y-1] = (char)79;              //sprawdzanie pola centralnego
      if(x-1>=1) {if(tab[2*x-3][2*y-1] == (char)88) tab[2*x-3][2*y-1] = (char)79;} //sprawdzanie pola na lewo
      if(y-1>=1) {if(tab[2*x-1][2*y-3] == (char)88) tab[2*x-1][2*y-3] = (char)79;} //sprawdzanie pola od góry
      if(y+1<=8) {if(tab[2*x-1][2*y+1] == (char)88) tab[2*x-1][2*y+1] = (char)79;} //sprawdzanie pola od dołu
      if(x+1<=8) {if(tab[2*x+1][2*y-1] == (char)88) tab[2*x+1][2*y-1] = (char)79;} //sprawdzanie pola na prawo
}