#pragma once
#include<vector>
#include<iostream>

namespace game {
	class Board {
	public:
		Board();
		Board(unsigned int _boardSize, const char _separator);
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
		unsigned int boardSize = 0;
		unsigned int  movementsNum = 0;
		bool isRunning = false;
		char separator = '/';
	};

	std::ostream& operator<<(std::ostream& os, const Board& board);
	void clearTerminal();
}