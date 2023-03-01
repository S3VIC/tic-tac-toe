#include "board.h"
#include<iostream>

namespace game {
	Board::Board()
		: board(std::vector<std::vector<char>> {}), boardSize(0), separator('/') {
	}

	Board::Board(size_t _boardSize, const char _separator)
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

	void Board::move(const int& x, const int& y) {
		if (boardSize > 1)
		{
			// x field coords
			const int xleftPos = 2 * x - 3;
			const int xrightPos = 2 * x + 1;
			const int xCentralPos = 2 * x - 1;

			// y field coords
			const int yDownPos = 2 * y + 3;
			const int yUpPos = 2 * y + -3;
			const int yCentralPos = 2 * y - 1;
			if (x < boardSize && y < boardSize) {

				//checking central point
				if (this->board[xCentralPos][yCentralPos] == (char)88)
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
		else {
			//checking central point
			if (this->checkField(2 * x - 1, 2 * y - 1))
				this->board[2 * x - 1][2 * y - 1] = (char)79;
		}
	}

	bool Board::checkField(const int& x, const int& y) {
		bool changeFieldSign = false;

		if (this->board[x][y] == (char)88)
			changeFieldSign = true;

		return changeFieldSign;
	}

	void game::Board::checkMove(const int& x, const int& y) {
		bool validMove = false;
		if (this->board[2 * x - 1][2 * y - 1] == (char)88)
			validMove = true;

		if (validMove)
			this->move(x, y);
		else
			std::cout << "Move not valid. Try again" << std::endl;
	}



	void game::clearTerminal() {
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
	}

	Board::~Board() {}
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