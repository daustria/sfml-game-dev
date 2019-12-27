#include "tilemap.h"
#include <iostream>

TileMap::TileMap(): tileWidth(32), tileHeight(24), width(20), height(20), size(400)
{
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(size*4);

	for (int i = 0; i < size; ++i)
	{
		sf::Vertex *quad = &vertices[i*4];

		int row = i/height;
		int col = i%width;


		quad[0].position = sf::Vector2f(row*tileWidth, col*tileHeight);
		quad[1].position = sf::Vector2f((row+1)*tileWidth, col*tileHeight);
		quad[2].position = sf::Vector2f((row+1)*tileWidth, (col+1)*tileHeight);
		quad[3].position = sf::Vector2f(row*tileWidth,(col+1)*tileHeight);

		quad[0].color = sf::Color::White;
		quad[1].color = sf::Color::Black;
		quad[2].color = sf::Color::Black;
		quad[3].color = sf::Color::Black;
	}
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const 
{
	target.draw(vertices, states);
}
