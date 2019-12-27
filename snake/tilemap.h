#ifndef TILE_MAP_H
#define TILE_MAP_H
#include <SFML/Graphics.hpp>
class TileMap : public sf::Drawable
{
	public:
		TileMap();
	private:
		virtual void draw(sf::RenderTarget &, sf::RenderStates states) const;
		const int tileWidth;
		const int tileHeight;
		const int width;
		const int height;
		const int size;
		sf::VertexArray vertices;
};
#endif //TILE_MAP_H
