#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

class Game
{
	public:
		Game();
		void run();

	private:
		static const float PlayerSpeed;
		void processEvents();
		void update(sf::Time);
		void render();
		void handlePlayerInput(sf::Keyboard::Key, bool);

		sf::RenderWindow mWindow;
		sf::CircleShape mPlayer;

		bool mIsMovingUp;
		bool mIsMovingDown;
		bool mIsMovingRight;
		bool mIsMovingLeft;
};
#endif //GAME_H
