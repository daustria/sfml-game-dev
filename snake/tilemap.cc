#include "tilemap.h"
#include <iostream>

TileMap::TileMap(): tileWidth(32), tileHeight(24), width(20), height(20), size(400)
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

void TileMap::processInput(sf::Keyboard::Key key)
{
}

void TileMap::update()
{

}

int TileMap::getCellIndex(int x, int y) const
{
	int row = y/tileHeight;
	int col = x/tileWidth;
	return row*width + col;
}

void TileMap::moveSnake()
{

}


void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	for (auto &it : cells)
		(*it).draw(target, states);
}
