#include "bullet.h"

Bullet::Bullet(const int &x, const int &y) : offsetY(2)
{
	r.setPosition(x, y + offsetY);
	r.setSize(sf::Vector2f(5,25));
	r.setOutlineColor(sf::Color::Yellow);
	r.setOutlineThickness(5);
}

void Bullet::move(const sf::Vector2f &movement)
{
	r.move(movement);
}

sf::Vector2f Bullet::pos()
{
	return r.getPosition();
}

sf::RectangleShape Bullet::getRect()
{
	return r;
}

