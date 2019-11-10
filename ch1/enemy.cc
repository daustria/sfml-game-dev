#include <math.h>
#include "enemy.h"
#define PI 3.141592654

Enemy::Enemy(const int & x, const int & y, const sf::Vector2f & mv, const int & radius, const int & life): 
	movement(mv),
	health(life)
{
	c.setRadius(radius);
	c.setPosition(x, y);
	c.setFillColor(sf::Color::Red);
}

sf::CircleShape Enemy::shape() const
{
	return c;
}

sf::Vector2f Enemy::pos() const
{
	return c.getPosition();
}

bool Enemy::offscreen(const sf::Window &display) const
{
	const sf::Vector2u v = display.getSize();
	int y = this->pos().y;
	return (y < - 100 || y > v.y);
}

sf::FloatRect Enemy::hitbox() const
{
	const float radius = c.getRadius();
	const sf::Vector2f pos = c.getPosition();

	const float left = pos.x + radius * cos(PI/4);
	const float top = pos.y + radius * sin(PI/4);

	return sf::FloatRect(left, top, radius, radius);
}

void Enemy::move(const sf::Time & delta)
{
	c.move(movement * delta.asSeconds());
}

void Enemy::removeHealth(const int & damage)
{
	health -= damage;
}

bool Enemy::dead() const
{
	return health <= 0;
}
