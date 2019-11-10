#include "bullet.h"

Bullet::Bullet(const int &x, const int &y, const int &offX, const int &offY, const sf::Vector2f &direction): 
	offsetX(offX), offsetY(offY), movement(direction)
{
	r.setPosition(x + offsetX, y + offsetY);
	r.setSize(sf::Vector2f(2,5));
	r.setOutlineColor(sf::Color::Yellow);
	r.setOutlineThickness(5);
}

void Bullet::move(const sf::Time &delta)
{
	r.move(movement*delta.asSeconds());
}

sf::Vector2f Bullet::pos() const
{
	return r.getPosition();
}

sf::RectangleShape Bullet::shape() const
{
	return r;
}

bool Bullet::offscreen(const sf::Window & display) const
{
	const sf::Vector2u v = display.getSize();
	int y = this->pos().y;
	return (y < -100 || y > v.y);
}



