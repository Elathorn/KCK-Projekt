#pragma once

#include <SFML\Graphics.hpp>
#include "Mechanic.h"
#include "GraphicsConfig.h"
#include "IOManager.h"
using namespace sf;
class TextBase
{
public:
	TextBase(RenderWindow& window, int borderXAxis);
	void drawAllContent();
	void addText(string textToAdd);
	void addText(char charToAdd);

private:
	static const int TEXT_LINES = 5; //okresla iloœæ linii tekstu w programie
	static const int FONT_SIZE = 100/TEXT_LINES;
	Text * _text[TEXT_LINES];
	RenderWindow& _window;
	Font * _font;
	int _borderXAxis;
};


