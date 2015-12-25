#include "TextView.h"
#include <iostream>
TextView::TextView(RenderWindow & window, int borderXAxis) : _window(window)
{
	Text * _text = new Text();
	Font * _font = new Font();
	if (!_font->loadFromFile("lucon.ttf")) ErrorHandler::errorMessage(100,"fonta");
	_text->setString("Siemanko!");
	_text->setFont(*_font);
	_text->setPosition(150, 150);
	_text->setColor(sf::Color::Red);
	_text->setCharacterSize(80);
}

void TextView::drawAllContent()
{
	_window.draw(_text);
}
