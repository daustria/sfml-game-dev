#include "game.h"
#include "bullet.h"
using namespace std;

const float Game::PlayerSpeed = 300.f;
const float Game::BulletSpeed = 900.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game(): maxBullets(1000), mWindow(sf::VideoMode(640, 480), "SFML Application"), mTexture(), mPlayer()
{

	if(!mTexture.loadFromFile("Eagle.png"))
	{
		//...do something later
	}

	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);

	mIsMovingLeft = false;
	mIsMovingRight = false;
	mIsMovingUp = false;
	mIsMovingDown = false;
	mFire = false;
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

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
		sf::Time delta = deltaTime;
		sf::Vector2f pos = mPlayer.getPosition();
		shared_ptr<Bullet> b(new Bullet(pos.x, pos.y));
		bullets.push_back(b);
	}

	mPlayer.move(movement * deltaTime.asSeconds());

	for (auto &b : bullets){
		sf::Vector2f pos = b->pos();
		if (pos.y < -100)
			continue;
		b->move(bulletMovement * deltaTime.asSeconds());
	}
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	for (auto &b : bullets)
		mWindow.draw(b->getRect());
	mWindow.display();
}
