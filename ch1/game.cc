#include <iostream>
#include <string>
#include "game.h"
#include "bullet.h"
#include "enemy.h"
using namespace std;

const float Game::PlayerSpeed = 300.f;
const float Game::BulletSpeed = 900.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game(): mWindow(sf::VideoMode(640, 480), "SFML Application"), mTexture(), mPlayer(), shotInterval(sf::seconds(2.f/60.f))
{

	if(!mTexture.loadFromFile("Eagle.png"))
	{
		//...handle error
	}

	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(300.f, 300.f);

	mIsMovingLeft = false;
	mIsMovingRight = false;
	mIsMovingUp = false;
	mIsMovingDown = false;
	mFire = false;

	bulletTimer;
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;


	sf::Vector2f zerovec(0, 0);
	shared_ptr<Enemy> e(new Enemy(100, 100, zerovec));
	enemies.push_back(e);

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while(timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}

}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
	else if (key == sf::Keyboard::Space) {
		mFire = isPressed;
	}

}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void swapWithLast(vector<shared_ptr<Bullet>> & vec, shared_ptr<Bullet> & ptr)
{
	shared_ptr<Bullet> tmp = vec.back();
	vec.back() = ptr;
	ptr = tmp;
	tmp.reset();
}

void swapWithLast(vector<shared_ptr<Enemy>> & vec, shared_ptr<Enemy> & ptr)
{
	shared_ptr<Enemy> tmp = vec.back();
	vec.back() = ptr;
	ptr = tmp;
	tmp.reset();
}

void Game::clearInactiveBullets()
{
	for (auto it = bullets.begin() ; it != bullets.end() ; )
		if ((*it)->offscreen(mWindow) || (*it)->hitSomething) {
			swapWithLast(bullets, *it);
			bullets.back().reset();
			bullets.pop_back();
		} else {
			++it;
		}
}

void Game::handleShotEnemies()
{
	for (auto it = enemies.begin(); it != enemies.end() ; )
	{

		cout << (*it)->dead() << endl;

		for (auto &b : bullets)
		{
			if (b->hitbox().intersects((*it)->hitbox())) {
				b->hitSomething = true;
				(*it)->removeHealth(b->getDamage());
			}
		}

		if ((*it)->dead()) {
			swapWithLast(enemies, *it);
			enemies.back().reset();
			enemies.pop_back();
		} else {
			++it;
		}
	}

}


void Game::update(sf::Time deltaTime)
{

	sf::Vector2f movement(0.f, 0.f);

	sf::Vector2f bulletMovement(0.f, -1*BulletSpeed);

	if (mIsMovingUp)
		movement.y -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;
	if (mFire) {

		sf::Time t = bulletTimer.getElapsedTime();

		if(t > shotInterval) {
			sf::Vector2f pos = mPlayer.getPosition();
			//offset the bullet to appear above the player
			shared_ptr<Bullet> b(new Bullet(pos.x, pos.y, 22, 2, bulletMovement));
			bullets.push_back(b);
			bulletTimer.restart();
		}
	}

	mPlayer.move(movement * deltaTime.asSeconds());


	// move bullets 
	for (auto it = bullets.begin(); it != bullets.end(); ++it)
		(*it)->move(deltaTime);

	handleShotEnemies();
	cout << "handled shot enemies" << endl;
	clearInactiveBullets();
	cout << "cleared inactive bullets" << endl;

}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	for (auto &b : bullets)
		mWindow.draw(b->shape());
	for (auto &e : enemies)
		mWindow.draw(e->shape());
	mWindow.display();
}
