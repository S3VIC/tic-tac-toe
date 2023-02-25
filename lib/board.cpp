#include "board.h"
#include<iostream>

game::Board::Board()
	: board(std::vector<std::vector<char>> {}), boardSize(0), separator('/') {
}

game::Board::Board(size_t _boardSize, const char _separator)
	: board(std::vector<std::vector<char>> {}), boardSize(_boardSize), separator(_separator) 
{
	for (int i = 0; i < 2 * boardSize + 1; i++) {
		std::vector<char> column = {};
		
		for (int k = 0; k < 2 * boardSize + 1; k++) {
			
			if (i % 2 == 1 && k % 2 == 1) 
				column.push_back((char)88);
			else 
				column.push_back((char)92);
		}
		board.push_back(column);
	}
}

void game::Board::move(const int& x, const int& y) {
	if (x < boardSize && y < boardSize) {

		//checking central point
		if (this->board[2 * x - 1][2 * y - 1] == (char)88) 
			this->board[2 * x - 1][2 * y - 1] = (char)79;              		

		//checkign field to the left
		if (x - 1 >= 1) { 
			if (this->board[2 * x - 3][2 * y - 1] == (char)88) 
				this->board[2 * x - 3][2 * y - 1] = (char)79; 
		} 
		
		//checking one field up
		if (y - 1 >= 1) { 
			if (this->board[2 * x - 1][2 * y - 3] == (char)88) 
				this->board[2 * x - 1][2 * y - 3] = (char)79; 
		} 
		
		//checking one field down
		if (y + 1 <= 8) {
			if (this->board[2 * x - 1][2 * y + 1] == (char)88) 
				this->board[2 * x - 1][2 * y + 1] = (char)79;
		} 
		
		//checking field to the right
		if (x + 1 <= 8) {
			if (this->board[2 * x + 1][2 * y - 1] == (char)88) 
				this->board[2 * x + 1][2 * y - 1] = (char)79; 
		} 
	}
}

std::ostream& game::operator<<(std::ostream& os, const Board& board) {
	
	for (int i = 0; i < 2 * board.boardSize + 1; i++) {
		for (int k = 0; k < 2 * board.boardSize + 1; k++) {
			os << ' ' << board.board[i][k];
		}
		os << '\n';
	}
	return os;
}

void game::clearTerminal() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

game::Board::~Board(){}