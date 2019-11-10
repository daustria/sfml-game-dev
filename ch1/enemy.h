#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>


class Enemy
{
	public:
		Enemy(const int &, const int &, const sf::Vector2f &, const int & radius = 25.f, const int & life = 100);

		void move (const sf::Time &);
		sf::Vector2f pos() const;
		sf::CircleShape shape() const;

		bool offscreen(const sf::Window &) const;

		sf::FloatRect hitbox() const;

		void removeHealth(const int &);

		bool dead() const;

	private:
		sf::CircleShape c;
		const sf::Vector2f movement;
		int health;
};
#endif //ENEMY_H
