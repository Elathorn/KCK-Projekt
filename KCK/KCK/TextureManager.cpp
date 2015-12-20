#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

sf::Texture * TextureManager::getTexture(string name)
{
	return IOManager::loadTextureFromFile(name + ".png");
}
