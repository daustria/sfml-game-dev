#ifndef TILE_MAP_H
#define TILE_MAP_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "cell.h"
#include "snakecell.h"
class TileMap : public sf::Drawable
{
	public:
		TileMap();
//		~TileMap();
//		TileMap(const TileMap &) = delete;
//		const TileMap &operator=(const TileMap &) = delete;
	private:
		virtual void draw(sf::RenderTarget &, sf::RenderStates states) const;
		const int tileWidth;
		const int tileHeight;
		const int width;
		const int height;
		const int size;

		std::shared_ptr<SnakeCell> head; 
		std::shared_ptr<Cell> food; 
		std::vector<std::shared_ptr<Cell>> cells;
};
#endif //TILE_MAP_H
