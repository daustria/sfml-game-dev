#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>


class Enemy
{
	public:
		Enemy(int x, int y, const sf::Vector2f &, float radius = 25.f, int life = 100);

		void move (const sf::Time &);
		sf::Vector2f pos() const;
		sf::CircleShape shape() const;

		bool offscreen(const sf::Window &) const;

		sf::FloatRect hitbox() const;

		void removeHealth(int);

		bool dead() const;

		void setMovement(const sf::Vector2f &);

	private:
		sf::CircleShape c;
		sf::Vector2f movement;
		int health;
};
#endif //ENEMY_H
