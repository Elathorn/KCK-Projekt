#include "TextView.h"
#include <iostream>
#include <queue>
TextBase::TextBase(RenderWindow & window, int borderXAxis) : _window(window)
{
	_font = new Font();
	if (!_font->loadFromFile("lucon.ttf")) ErrorHandler::errorMessage(100, "lucon.ttf");
	for (int i = 0; i < TEXT_LINES; i++)
	{
		_text[i] = new Text();
		_text[i]->setString("SAMPLE TEXT");
		_text[i]->setFont(*_font);
		_text[i]->setPosition(0, borderXAxis + (FONT_SIZE * 1.5 * i));
		if (i==4) _text[i]->setColor(sf::Color::Red);
		else  _text[i]->setColor(sf::Color::White);
		_text[i]->setCharacterSize(FONT_SIZE);
	}
}

void TextBase::drawAllContent()
{
	for (int i = 0; i < TEXT_LINES; i++)
	_window.draw(*_text[i]);
}

void TextBase::addText(string textToAdd)
{
	for (int i = 0; i < TEXT_LINES-1; i++)
	{
		_text[i] = _text[i + 1];
	}
	_text[TEXT_LINES-1]->setString(textToAdd);
}

void TextBase::addText(char charToAdd)
{
	string tempString = _text[TEXT_LINES - 1]->getString();
	tempString += charToAdd;
	_text[TEXT_LINES - 1]->setString(tempString);
}
