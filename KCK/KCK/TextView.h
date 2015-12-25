#pragma once

#include <SFML\Graphics.hpp>
#include "Mechanic.h"
#include "GraphicsConfig.h"
#include "IOManager.h"
using namespace sf;
class TextView
{
public:
	TextView(RenderWindow& window, int borderXAxis);
	void drawAllContent();

private:
	Text _text;
	RenderWindow& _window;
	Mechanic* _mech;
	Font* _font;
	int _borderXAxis;
};


