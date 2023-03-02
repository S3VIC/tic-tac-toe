#include "board.h"

#define BOARD_MIN_SIZE 1
namespace game {
	Board::Board()
		: board(std::vector<std::vector<char>> {}), boardSize(0), separator('/') {
	}

	Board::Board(unsigned int _boardSize, const char _separator)
		: board(std::vector<std::vector<char>> {}), boardSize(_boardSize), movementsNum(0),
		separator(_separator)
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
		movementsNum = _boardSize * _boardSize;
		isRunning = true;
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
				
				if (checkField(xCentralPos, yCentralPos))
					changeSign(xCentralPos, yCentralPos);

				//checkign field to the left
				if (x - 1 >= BOARD_MIN_SIZE) {
					if (checkField(xleftPos, yCentralPos))
						changeSign(xleftPos, yCentralPos);
				}

				//checking one field up
				if (y - 1 >= BOARD_MIN_SIZE) {
					if (checkField(xCentralPos, yUpPos))
						changeSign(xCentralPos, yUpPos);
				}

				//checking one field down
				if (y + 1 <= boardSize) {
					if (checkField(xCentralPos, yDownPos))
						changeSign(xCentralPos, yDownPos);
				}

				//checking field to the right
				if (x + 1 <= boardSize) {
					if (checkField(xrightPos, yCentralPos))
						changeSign(xrightPos, yCentralPos);
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

	void Board::changeSign(const int& x, const int& y) {
		this->board[x][y] = char(79);
		if (movementsNum > 0)
			movementsNum--;
		else
			isRunning = false;
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

	bool Board::ifRunning() {
		return isRunning;
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