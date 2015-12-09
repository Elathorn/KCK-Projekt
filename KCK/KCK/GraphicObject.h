#pragma once
#include <SFML/Graphics.hpp>
class GraphicObject
{
public:
	virtual sf::Sprite getSprite() = 0;
private:
	GraphicObject() {};
	~GraphicObject() {};
};

