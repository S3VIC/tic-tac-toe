#pragma once
#include<vector>
#include<iostream>

namespace game {
	class Board {
	public:
		Board();
		Board(uint32_t _boardWidth, uint32_t _boardHeight, const char _separator);
		virtual ~Board();
		void move(const int& x, const int& y);
		bool checkMove(const int& x, const int& y);
		bool checkField(const int& x, const int& y);
		void changeSign(const int& x, const int& y);
		bool ifRunning();
		int getMovementsLeft();
		void checkMovementsLeft();
		friend std::ostream& operator<<(std::ostream& os, const Board& board);
	
	private:
		std::vector<std::vector<char>> board = {};
		uint32_t boardWidth = 0;
		uint32_t boardHeight = 0;
		uint64_t  movementsNum = 0;
		bool isRunning = false;
		char separator = '/';
	};

	std::ostream& operator<<(std::ostream& os, const Board& board);
	void clearTerminal();
	void displayWelcomeMessage(void);
	
	void displayStatusAndDefineMove(uint32_t* x, uint32_t* y, Board& board);
	uint32_t getBoardWidth(void);
	uint32_t getBoardHeight(void);

}