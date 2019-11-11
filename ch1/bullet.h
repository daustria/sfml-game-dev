#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>

class Bullet
{
	public:
		Bullet(int x, int y, int offX, int offY, const sf::Vector2f &, int dmg = 20);
		void move(const sf::Time &);
		sf::Vector2f pos() const;
		sf::RectangleShape shape() const;
		bool offscreen(const sf::Window &) const;
		sf::FloatRect hitbox() const;
		bool hitSomething;
		int getDamage() const;
	private:
		const int offsetX;
		const int offsetY;
		sf::RectangleShape r;
		const sf::Vector2f movement;
		const int damage;
};
#endif //BULLET_H
