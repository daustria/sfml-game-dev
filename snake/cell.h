#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
class Cell : public sf::Drawable
{

	friend class TileMap;

	public:
		Cell(int w, int h, int topLeftX, int topLeftY);

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

		const int width;
		const int height;
		const int x;
		const int y;

		Cell *left;
		Cell *right;
		Cell *up;
		Cell *down;

		sf::VertexArray vertices;
};
#endif //CELL_H
