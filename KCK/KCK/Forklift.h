#pragma once
#include <SFML/Graphics.hpp>
#include "GraphicsConfig.h"
#include "TextureManager.h"


class Forklift
{
public:
	Forklift(sf::RenderWindow& window, TextureManager * TM);
	~Forklift();
	const static int FORKLIFT_MOVEMENT_SPEED = 10;
	void setTexture(sf::Texture * text) { _sprite->setTexture(*text); }
	sf::Sprite * getSprite() { return _sprite; }
	void drawAllContent();
	sf::Sprite * _sprite;
	sf::Vector2f _animationVector;
	void prepareDataForAnimation(string endPos);

private:
	int _animationIterator = 0;
	sf::Vector2i _coord;
	sf::RenderWindow& _window;
	TextureManager * _TM;
};

