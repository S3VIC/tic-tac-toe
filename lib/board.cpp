#include "board.h"
#include "board.h"

#define BOARD_MIN_SIZE 1
namespace game {
	Board::Board()
		: board(std::vector<std::vector<char>> {}), boardWidth(0), boardHeight(0), separator('/') {
	}

	Board::Board(uint32_t _boardWidth, uint32_t _boardHeight, const char _separator)
		: board(std::vector<std::vector<char>> {}), boardWidth(_boardWidth), boardHeight(_boardHeight),
		movementsNum(0), separator(_separator)
	{
		for (int i = 0; i < boardHeight; i++) {
			std::vector<char> column = {};

			for (int k = 0; k < boardWidth; k++) {
					column.push_back((char)88);
			}
			board.push_back(column);
		}
		movementsNum = boardWidth * boardHeight;
		isRunning = true;
	}

	void Board::move(const int& x, const int& y) {
		
		const int xCentralPos = x - 1;
		const int yCentralPos = y - 1;
		
		clearTerminal();

		if (movementsNum > 0)
		{
			// x field coords
			const int xleftPos = x - 2;
			const int xrightPos = x;
			

			// y field coords
			const int yDownPos = y;
			const int yUpPos = y - 2;
			
			if (x <= boardWidth && y <= boardHeight) {

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
				if (y + 1 <= boardHeight) {
					if (checkField(xCentralPos, yDownPos))
						changeSign(xCentralPos, yDownPos);
				}

				//checking field to the right
				if (x + 1 <= boardWidth) {
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

	void clearTerminal() {
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

	for (int i = 0; i < 2 * board.boardWidth + 1; i++)
		os << board.separator << ' ';
	
	os << '\n';

	for (int i = 0; i < board.boardHeight; i++) {
		for (int k = 0; k < board.boardWidth; k++) 
			os << board.separator << ' ' << board.board[i][k] << ' ';
		os << board.separator << '\n';
	}

	for (int i = 0; i < 2 * board.boardWidth + 1; i++)
		os << board.separator << ' ';
	os << '\n';
	return os;
}

void game::displayWelcomeMessage(void) {
	std::cout << "Welcome to TTT game!\n";
	std::cout << "Choose board size:" << '\n';
}

uint32_t game::getBoardWidth(void) {
	uint32_t boardWidth = 0;
	std::cout << "Board Width: ";
	std::cin >> boardWidth;
	
	return boardWidth;
}

uint32_t game::getBoardHeight(void) {
	uint32_t boardHeight = 0;
	std::cout << "Board Height: ";
	std::cin >> boardHeight;

	return boardHeight;
}

void game::displayStatusAndDefineMove(uint32_t* x, uint32_t* y, Board& board) {
	std::cout << board;
	std::cout << "Movements left: " << board.getMovementsLeft() << '\n';
	std::cout << "Row: ";
	std::cin >> *x;
	std::cout << "Column: ";
	std::cin >> *y;
}
