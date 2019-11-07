#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.h"

class Game
{
	public:
		Game();
		void run();

	private:
		static const float PlayerSpeed;
		static const sf::Time TimePerFrame;

		void processEvents();
		void update(sf::Time);
		void render();
		void handlePlayerInput(sf::Keyboard::Key, bool);

		sf::RenderWindow mWindow;
		sf::Texture mTexture;
		sf::Sprite mPlayer;

		std::vector<Bullet*> bullets;
		const int maxBullets;

		bool mIsMovingUp;
		bool mIsMovingDown;
		bool mIsMovingRight;
		bool mIsMovingLeft;
		bool mFire;

};
#endif //GAME_H
