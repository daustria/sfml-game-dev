#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
class Cell : public sf::Drawable
{

	friend class TileMap;
	friend std::ostream &operator<<(std::ostream &, const Cell &);

	public:
		Cell(int w, int h, int topLeftX, int topLeftY);	
		virtual ~Cell() = default;
		void setColour(sf::Color);

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		const int width;
		const int height;
		const int x;
		const int y;

		std::shared_ptr<Cell> left;
		std::shared_ptr<Cell> right;
		std::shared_ptr<Cell> up;
		std::shared_ptr<Cell> down;

		sf::VertexArray vertices;
};
std::ostream &operator<<(std::ostream &out, const Cell &c);
#endif //CELL_H
