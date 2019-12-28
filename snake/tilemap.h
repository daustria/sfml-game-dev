#ifndef TILE_MAP_H
#define TILE_MAP_H
#include "cell.h"
#include <SFML/Graphics.hpp>
#include <vector>

class TileMap : public sf::Drawable
{
	public:
		TileMap();
		~TileMap();
		TileMap(const TileMap &) = delete;
		TileMap &operator=(const TileMap &) = delete;
		
	private:
		virtual void draw(sf::RenderTarget &, sf::RenderStates states) const;
		const int tileWidth;
		const int tileHeight;
		const int width;
		const int height;
		const int size;

		std::vector<Cell *> cells;
};
#endif //TILE_MAP_H
