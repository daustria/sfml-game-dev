#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
	public:
		Bullet(const int &, const int &, const int &, const int &, const sf::Vector2f &);
		void move(const sf::Time &);
		sf::Vector2f pos() const;
		sf::RectangleShape shape() const;
		bool offscreen(const sf::Window &) const;
		sf::FloatRect hitbox() const;
	private:
		const int offsetY;
		const int offsetX;
		sf::RectangleShape r;
		const sf::Vector2f movement;
		sf::FloatRect collisionbox;
};
#endif //BULLET_H
