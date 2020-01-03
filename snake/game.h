#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "tilemap.h"

class Game
{
	public:
		Game();
		void run();
	private:
		void processEvents();
		void update();
		void render();
		void handlePlayerInput(sf::Keyboard::Key);

		sf::RenderWindow mWindow;
		TileMap tmap;

		static sf::Time timePerFrame;
		
};
#endif //GAME_H
