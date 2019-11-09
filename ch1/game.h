#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "bullet.h"

class Game
{
	public:
		Game();
		void run();

	private:
		static const float PlayerSpeed;
		static const float BulletSpeed;
		static const sf::Time TimePerFrame;
		
		void processEvents();
		void update(sf::Time);
		void render();
		void handlePlayerInput(sf::Keyboard::Key, bool);

		sf::RenderWindow mWindow;
		sf::Texture mTexture;
		sf::Sprite mPlayer;
		sf::Clock bulletTimer;

		std::vector<std::shared_ptr<Bullet>> bullets;

		const sf::Time shotInterval;

		bool mIsMovingUp;
		bool mIsMovingDown;
		bool mIsMovingRight;
		bool mIsMovingLeft;
		bool mFire;

};
#endif //GAME_H
