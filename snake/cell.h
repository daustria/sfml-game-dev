#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "states.h"
class Cell : public sf::Drawable
{

	friend class TileMap;
	friend std::ostream &operator<<(std::ostream &, const Cell &);

	public:
		Cell(int w, int h, int topLeftX, int topLeftY);	
		virtual ~Cell() = default;
		void setColour(sf::Color);
		int getX() const;
		int getY() const;
		virtual void setState(std::shared_ptr<CellState> newState);

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		const int width;
		const int height;
		const int x;
		const int y;

		sf::VertexArray vertices;

		std::shared_ptr<CellState> state;
};
std::ostream &operator<<(std::ostream &out, const Cell &c);
#endif //CELL_H
