#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <memory>
#include <map>
#include <SFML/Graphics.hpp>
enum class TextureID { Landscape, Airplane, Missile };

class TextureHolder
{
	public:
		void load(TextureID, const std::string & fname);
	private:
		std::map<TextureID, std::unique_ptr<sf::Texture>> mTextureMap;
};
#endif //TEXTURE_HOLDER_H
