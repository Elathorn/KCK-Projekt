#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsConfig.h"
#include "TextureManager.h"


class Forklift
{
public:
	Forklift(sf::RenderWindow& window, TextureManager * TM);
	~Forklift();

	void setTexture(sf::Texture * text) { _sprite->setTexture(*text); }
	sf::Sprite * getSprite() { return _sprite; }
	void drawAllContent();

private:
	sf::Sprite * _sprite;
	sf::Vector2i _coord;
	sf::RenderWindow& _window;
	TextureManager * _TM;
};

