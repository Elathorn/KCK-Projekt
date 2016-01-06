#include "TextView.h"
TextBase::TextBase(RenderWindow & window, int borderXAxis) : _window(window)
{
	_font = new Font();
	if (!_font->loadFromFile("lucon.ttf")) ErrorHandler::errorMessage(100, "lucon.ttf");
	for (int i = 0; i < TEXT_LINES; i++)
	{
		_text[i] = new Text();
		_text[i]->setFont(*_font);
		_text[i]->setPosition(0, borderXAxis + (FONT_SIZE * 1.5 * i));
		if (i==TEXT_LINES-1) 
		{
			_text[i]->setColor(sf::Color::Red);
			_text[i]->setString("");
		}
		else
		{
			_text[i]->setColor(sf::Color::White);
#ifdef _DEBUG
			_text[i]->setString("DEBUG");
#else
			_text[i]->setString("");
#endif
		}
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
	for (int i = 0; i < TEXT_LINES; i++)
	{
		_text[i]->setString(_text[i + 1]->getString());
	}
	_text[TEXT_LINES - 1]->setString(textToAdd);
}

void TextBase::modifyTextByChar(char charToAdd)
{
	string tempString = _text[TEXT_LINES - 1]->getString();
	if (int(charToAdd) != UNICODE_BACKSPACE_CODE)
	tempString += charToAdd;
	else if (tempString.length() > 0) tempString.pop_back();
	_text[TEXT_LINES - 1]->setString(tempString);
}

string TextBase::getLastLine()
{
	return _text[TEXT_LINES-1]->getString();
}
