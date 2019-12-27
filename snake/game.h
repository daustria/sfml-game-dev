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
		
		sf::RenderWindow mWindow;
		TileMap tmap;
		
};
#endif //GAME_H
