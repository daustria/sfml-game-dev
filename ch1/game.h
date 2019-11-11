#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "bullet.h"
#include "enemy.h"

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
		void spawnEnemies(int n, int rows);

		sf::RenderWindow mWindow;
		sf::Texture mTexture;
		sf::Sprite mPlayer;

		sf::Clock bulletTimer;
		sf::Clock enemyMoveTimer;

		std::vector<std::shared_ptr<Bullet>> bullets;
		std::vector<std::shared_ptr<Enemy>> enemies;

		const sf::Time shotInterval;

		void clearInactiveBullets();
		void handleShotEnemies();

		bool mIsMovingUp;
		bool mIsMovingDown;
		bool mIsMovingRight;
		bool mIsMovingLeft;
		bool mFire;

};
#endif //GAME_H
