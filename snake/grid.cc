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
		cells.push_back(cp);
	}

	int k = 0;
	for(const auto &it : cells) {
		std::cout << k << "," << *it << std::endl;
		++k;
	}

}

void Grid::processInput(sf::Keyboard::Key key)
{

}

void Grid::update()
{

}

int Grid::getCellIndex(int x, int y) const
{
	int row = y/tileHeight;
	int col = x/tileWidth;
	return row*width + col;
}

void Grid::moveSnake()
{

}


void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	for (auto &it : cells)
		(*it).draw(target, states);
}
