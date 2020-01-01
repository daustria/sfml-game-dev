#include "snakecell.h"

SnakeCell::SnakeCell(int w, int h, int topLeftX, int topLeftY, SnakeCell::Direction initialDir): Cell(w, h, topLeftX, topLeftY), dir(initialDir) 
{
	setColour(sf::Color::Blue);
}

