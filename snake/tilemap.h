#ifndef TILE_MAP_H
#define TILE_MAP_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "cell.h"
class TileMap : public sf::Drawable
{
	public:
		TileMap();
		void processInput(sf::Keyboard::Key);
		void update();
	private:
		virtual void draw(sf::RenderTarget &, sf::RenderStates states) const;
		void moveSnake();
		int getCellIndex(int x, int y) const;
		const int tileWidth;
		const int tileHeight;
		const int width;
		const int height;
		const int size;

		std::vector<std::shared_ptr<Cell>> cells;
};
#endif //TILE_MAP_H
