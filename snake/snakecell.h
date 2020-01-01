#ifndef SNAKE_CELL_H
#define SNAKE_CELL_H
#include "cell.h"

class SnakeCell : public Cell
{
	public:
		enum Direction{up, down, left, right};
		SnakeCell(int w, int h, int topLeftX, int topLeftY, Direction = right);
		virtual ~SnakeCell() = default;
	private:
		Direction dir; 
};
#endif //SNAKE_CELL_H
