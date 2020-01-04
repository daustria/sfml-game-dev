#include <iostream>
#include "grid.h"

Grid::Grid(): tileWidth(32), tileHeight(24), width(20), height(20), size(400)
{
	cells.reserve(size);

	//populate cells
	for(int i = 0; i < size; ++i)
	{
		int row = i/height;
		int col = i%width;

		int x = col*tileWidth;
		int y = row*tileHeight;

		auto cp = std::make_shared<Cell>(tileWidth, tileHeight, x, y);
		auto defaultState = std::make_shared<Normal>();
		cp->setState(defaultState);
		cells.push_back(cp);
	}

	int headIndex = 101;
	cells[headIndex]->snake();
	snakeIndices.push_back(headIndex);
}

void Grid::processInput(sf::Keyboard::Key key)
{
	auto head = cells[snakeIndices[0]];

	if (key == sf::Keyboard::W) { 
		head->changeDir(Direction::Up);
	} else if (key == sf::Keyboard::S) {
		head->changeDir(Direction::Down);
	} else if (key == sf::Keyboard::A) {
		head->state->changeDir(Direction::Left);
	} else if (key == sf::Keyboard::D) {
		head->changeDir(Direction::Right);
	}
}

void Grid::update()
{
	moveSnake();
}

int Grid::getCellIndex(int x, int y, Direction d) const
{
	int row = y/tileHeight;
	int col = x/tileWidth;
	int index = row*width + col;
	int retVal = -1;
	
	switch(d)
	{
		case Direction::None:
			retVal = index;
			break;
		case Direction::Up:
			retVal = index - width;
			break;
		case Direction::Down:
			retVal = index + width;
			break;
		case Direction::Left:
			retVal = index - 1;
			break;
		case Direction::Right:
			retVal = index + 1;
			break;
	}

	return retVal;
}

void Grid::moveSnake()
{
	auto head = cells[snakeIndices[0]];

	Direction lastDirection = head->dir();
	int newIndex = getCellIndex(head->x, head->y, head->dir());
	auto other = cells[newIndex];

	head->normal();
	other->snake(lastDirection);
	snakeIndices[0] = newIndex;
}


void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	for (auto &it : cells)
		(*it).draw(target, states);
}
