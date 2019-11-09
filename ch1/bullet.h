#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
	public:
		Bullet(const int &, const int &, const int &, const int &);
		void move(const sf::Vector2f &);
		sf::Vector2f pos();
		sf::RectangleShape getRect();
	private:
		const int offsetY;
		const int offsetX;
		sf::RectangleShape r;
};
#endif //BULLET_H
