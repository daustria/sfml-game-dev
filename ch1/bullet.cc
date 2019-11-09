#include "bullet.h"

Bullet::Bullet(const int & x, const int & y, const int &offX, const int &offY): offsetX(offX), offsetY(offY)
{
	r.setPosition(x + offsetX, y + offsetY);
	r.setSize(sf::Vector2f(2,5));
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

