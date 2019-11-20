#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <memory>
#include <map>
#include <SFML/Graphics.hpp>
enum class Texture { Landscape, Airplane, Missile };

class TextureHolder
{
	private:
		std::map<Texture, std::unique_ptr<sf::Texture>> mTextureMap;
};
#endif //TEXTURE_HOLDER_H
