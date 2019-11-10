#include "bullet.h"

Bullet::Bullet(const int &x, const int &y, const int &offX, const int &offY, const sf::Vector2f &direction, const int &dmg): 
	offsetX(offX), offsetY(offY), movement(direction), damage(dmg)
{
	r.setPosition(x + offsetX, y + offsetY);
	r.setSize(sf::Vector2f(2,5));
	r.setOutlineColor(sf::Color::Yellow);
	r.setOutlineThickness(5);
	hitSomething = false;
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

sf::FloatRect Bullet::hitbox() const
{
	return r.getGlobalBounds();
}

int Bullet::getDamage() const
{
	return damage;
}


