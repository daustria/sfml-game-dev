#include "cell.h"

Cell::Cell(int w, int h, int topLeftX, int topLeftY): 
	width(w), height(h), x(topLeftX), y(topLeftY), left(nullptr), right(nullptr), up(nullptr), down(nullptr), vertices(sf::Quads, 4)
{
	vertices[0].position = sf::Vector2f(x, y);
	vertices[1].position = sf::Vector2f(x + width, y);
	vertices[2].position = sf::Vector2f(x+width, y+height);
	vertices[3].position = sf::Vector2f(x, y+height);

	vertices[0].color = sf::Color::White;
	vertices[1].color = sf::Color::Black;
	vertices[2].color = sf::Color::Black;
	vertices[3].color = sf::Color::Black;
}

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(vertices); }
