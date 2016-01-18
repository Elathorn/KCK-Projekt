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
	void modifyTextByChar (char charToAdd);
	string getLastLine();
private:
	static const int TEXT_LINES = 5; //okresla iloœæ linii tekstu w programie
	const int FONT_SIZE = 100/TEXT_LINES;
	static const int UNICODE_BACKSPACE_CODE = 8;
	Text * _text[TEXT_LINES];
	RenderWindow& _window;
	Font * _font;
	int _borderXAxis;
};


