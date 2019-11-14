#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "game.h"
#include "bullet.h"
#include "enemy.h"
using namespace std;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game(): mWindow(sf::VideoMode(640, 480), "SFML Application"), 
	mTexture(), 
	mPlayer(), 
	shotInterval(sf::seconds(5.f/60.f)),
	enemyBoundary(100.f),
	PlayerSpeed(300.f),
	BulletSpeed(900.f)
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
}

vector<int> drawWithoutReplacement(int n, int k)
{
	vector<int> vec;
	for(int i = 1; i <= n; ++i)
		vec.emplace_back(i);

	random_shuffle(vec.begin(), vec.end());
	
	vector<int> sample;
	for(int i = 0; i < k; ++i)
		sample.emplace_back(vec.at(i));

	return sample;
}


void Game::spawnEnemies()
{
	const int maxEnemies = 10;
	const float width = mWindow.getSize().x;
	const float boundary = width/10;
	const float start = boundary;
	const float end = width - boundary;
	const float range = end - start;
	const float spawnInterval = range/maxEnemies;


	const int numEnemies = 5;
	vector<int> positionIndices = drawWithoutReplacement(maxEnemies, numEnemies);

	const sf::Vector2f movement(0.f, 100.f);



	for (auto &index : positionIndices)
	{
		shared_ptr<Enemy> e(new Enemy(start + spawnInterval*index, 0, movement));
		enemies.emplace_back(e);
	}
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	spawnEnemies();

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
	else if (key == sf::Keyboard::Space)
		mFire = isPressed;
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



template <typename PointerVec, typename gameObjPtr> 
void swapWithLast(PointerVec &v, gameObjPtr &p)
{
	gameObjPtr temp = v.back();
	v.back() = p;
	p = temp;
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
		for (auto &b : bullets)
		{
			if (b->hitbox().intersects((*it)->hitbox())) {
				b->hitSomething = true;
				(*it)->removeHealth(b->getDamage());
			}
		}

		if ((*it)->pos().y >= enemyBoundary)
		{
			const sf::Vector2f zero(0,0);
			(*it)->setMovement(zero);
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
	if (enemies.empty())
		spawnEnemies();

	handleShotEnemies();
	clearInactiveBullets();

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
			sf::Vector2f pos(mPlayer.getPosition());
			sf::Vector2f offset(24,2);
			//offset the bullet to appear above the player
			shared_ptr<Bullet> b(new Bullet(pos, offset, bulletMovement));
			bullets.push_back(b);
			bulletTimer.restart();
		}
	}

	mPlayer.move(movement * deltaTime.asSeconds());

	// move objects
	for (auto it = bullets.begin(); it != bullets.end(); ++it)
		(*it)->move(deltaTime);

	for (auto it = enemies.begin(); it != enemies.end(); ++it)
		(*it)->move(deltaTime);
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
