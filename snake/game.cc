#include <vector>
#include "game.h"

Game::Game():mWindow(sf::VideoMode(640, 480), "LoremIpsum")
{

}

void Game::run() 
{
	while(mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			mWindow.close();
	}

}
void Game::update() 
{
	mWindow.draw(tmap);
}

void Game::render() 
{
	mWindow.display();
}
