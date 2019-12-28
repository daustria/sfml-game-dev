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

		Cell *cp = new Cell{tileWidth, tileHeight, x, y};
		cells.push_back(cp);
	}

	//setup neighbours of cells
	for(int i = 0; i < size; ++i)
	{
		Cell *cell = cells[i];

		int up = i - width;
		int down = i + width;
		int left = i - 1;
		int right = i + 1;

		if (up >= 0)
			cell->left = cells[up];
		if (down >= 0)
			cell->down = cells[down];
		if (left >= 0)
			cell->left = cells[left];
		if (right >= 0)
			cell->right = cells[right];
	}
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	for (auto &it : cells)
		(*it).draw(target, states);
}


TileMap::~TileMap()
{
	for (auto &it : cells)
		delete it;
}
