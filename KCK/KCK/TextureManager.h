#pragma once
#include <SFML/Graphics.hpp>
#include "IOManager.h"
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	sf::Texture* getTexture(string name);
private:
};

