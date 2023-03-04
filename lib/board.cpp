#include "board.h"
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
		for (int i = 0; i < boardSize; i++) {
			std::vector<char> column = {};

			for (int k = 0; k < boardSize; k++) {
					column.push_back((char)88);
			}
			board.push_back(column);
		}
		movementsNum = _boardSize * _boardSize;
		isRunning = true;
	}

	void Board::move(const int& x, const int& y) {
		
		const int xCentralPos = x - 1;
		const int yCentralPos = y - 1;
		
		clearTerminal();

		if (boardSize > 1)
		{
			// x field coords
			const int xleftPos = x - 2;
			const int xrightPos = x;
			

			// y field coords
			const int yDownPos = y;
			const int yUpPos = y - 2;
			
			if (x <= boardSize && y <= boardSize) {

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
			if (this->checkField(xCentralPos, yCentralPos))
				changeSign(xCentralPos, yCentralPos);
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
		this->movementsNum--;
	}

	bool game::Board::checkMove(const int& x, const int& y) {
		bool validMove = false;
		if (this->board[x - 1][y - 1] == (char)88)
			validMove = true;

		return validMove;
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

	int Board::getMovementsLeft()
	{
		return movementsNum;
	}

	void Board::checkMovementsLeft() {
		if (!movementsNum)
			isRunning = false;
	}

	Board::~Board() {}
}

std::ostream& game::operator<<(std::ostream& os, const Board& board) {

	for (int i = 0; i < 2 * board.boardSize + 1; i++)
		os << board.separator << ' ';
	
	os << '\n';

	for (int i = 0; i < board.boardSize; i++) {
		for (int k = 0; k < board.boardSize; k++) 
			os << board.separator << ' ' << board.board[i][k] << ' ';
		os << board.separator << '\n';
	}

	for (int i = 0; i < 2 * board.boardSize + 1; i++)
		os << board.separator << ' ';
	os << '\n';
	return os;
}