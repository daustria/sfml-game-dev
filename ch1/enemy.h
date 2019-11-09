#ifndef ENEMY_H
#define ENEMY_h
#include <SFML/Graphics.hpp>


class Enemy
{
	public:
		Enemy(const int &, const int &, const sf::Vector2f &);
		void move (const sf::Time &);
		sf::Vector2f pos() const;
		sf::CircleShape shape() const;
		bool offscreen(const sf::Window &) const;
	private:
		sf::CircleShape shape;
		const sf::Vector2f movement;
}
#endif //ENEMY_H
