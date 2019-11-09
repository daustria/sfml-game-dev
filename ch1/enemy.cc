#include "enemy.h"

Enemy::Enemy(const int & x, const int & y, const sf::Vector2f & mv): movement(mv)
{
	shape.setRadius(5.f);
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::Red);

}

