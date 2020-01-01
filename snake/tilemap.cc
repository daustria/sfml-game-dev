#include "tilemap.h"
#include "snakecell.h"
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

		if (i == 57) {
			auto cp = std::make_shared<SnakeCell>(tileWidth, tileHeight, x, y);
			head = cp;
			cells.push_back(cp);
		} else { 
			auto cp = std::make_shared<Cell>(tileWidth, tileHeight, x, y);
			cells.push_back(cp);
		}
	}

	int k = 0;
	for(const auto &it : cells) {
		std::cout << k << "," << *it << std::endl;
		++k;
	}

	//setup neighbours of cells
	for(int i = 0; i < size; ++i)
	{
		std::shared_ptr<Cell> cell = cells[i];

		int up = i - width;
		int down = i + width;
		int left = i - 1;
		int right = i + 1;

		if (up >= 0)
			cell->up = cells[up];
		if (down < size)
			cell->down = cells[down];
		if (left/height == i/height && left >= 0)
			cell->left = cells[left];
		if (right/height == i/height && right < size)
 			cell->right = cells[right];

		std::cout << i << std::endl;

		if(cell->left) 
			std::cout << "left: " << *(cell->left) << std::endl;
		if(cell->right) 
			std::cout << "right: " << *(cell->right) << std::endl;
		if(cell->up) 
			std::cout << "up: " << *(cell->up) << std::endl;
		if(cell->down) 
			std::cout << "down: " << *(cell->down) << std::endl;

	}
}
void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	for (auto &it : cells)
		(*it).draw(target, states);
}


