#include "cell.h"

Cell::Cell(int w, int h, int topLeftX, int topLeftY): 
	width(w), height(h), x(topLeftX), y(topLeftY), vertices(sf::Quads, 4)
{
	vertices[0].position = sf::Vector2f(x, y);
	vertices[1].position = sf::Vector2f(x + width, y);
	vertices[2].position = sf::Vector2f(x+width, y+height);
	vertices[3].position = sf::Vector2f(x, y+height);

	vertices[0].color = sf::Color::Black;
	vertices[1].color = sf::Color::Black;
	vertices[2].color = sf::Color::Black;
	vertices[3].color = sf::Color::Black;
}

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(vertices); }

void Cell::setColour(sf::Color c)
{
	for(int i = 0; i < 4; ++i)
		vertices[i].color = c;
}

int Cell::getX() const { return x; }

int Cell::getY() const { return y; }

void Cell::setState(std::shared_ptr<CellState> newState) { state = newState; }

std::ostream &operator<<(std::ostream &out, const Cell &c)
{
	out << "x : " << c.x << ", y : " << c.y;
	return out;
}
