#pragma once
#include<vector>
#include<iostream>

namespace game {
	class Board {
	public:
		Board();
		Board(size_t _boardSize, const char _separator);
		virtual ~Board();
		friend std::ostream& operator<<(std::ostream& os, const Board& board);
	private:
		std::vector<std::vector<char>> board;
		size_t boardSize;
		char separator;
	};

	std::ostream& operator<<(std::ostream& os, const Board& board);
}