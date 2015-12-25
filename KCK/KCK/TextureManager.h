#pragma once
#include <SFML/Graphics.hpp>
#include "IOManager.h"
#include <vector>
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	sf::Texture* getTexture(string name);
private:
	vector < sf::Texture >  _textureBank;

};

