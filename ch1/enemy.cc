#include <math.h>
#include "enemy.h"
#define PI 3.141592654

Enemy::Enemy(const int & x, const int & y, const sf::Vector2f & mv, const int & radius): 
	movement(mv)
{
	c.setRadius(radius);
	c.setPosition(x, y);
	c.setFillColor(sf::Color::Red);

	collisionbox.left = x + radius*cos(PI/4);
	collisionbox.top = y + radius*sin(PI/4);
	collisionbox.width = radius;
	collisionbox.height = radius;
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
	return collisionbox;
}



