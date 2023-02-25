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

std::ostream& game::operator<<(std::ostream& os, const Board& board) {
	
	for (int i = 0; i < 2 * board.boardSize + 1; i++) {
		for (int k = 0; k < 2 * board.boardSize + 1; k++) {
			os << board.board[i][k];
		}
		os << '\n';
	}
	return os;
}

game::Board::~Board(){
}