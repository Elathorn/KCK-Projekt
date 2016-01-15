#include "TextureManager.h"


TextureManager::TextureManager()
{
	_textureBank.push_back(*IOManager::loadTextureFromFile("box.png"));
	_textureBank.push_back(*IOManager::loadTextureFromFile("floor.png"));
	_textureBank.push_back(*IOManager::loadTextureFromFile("forklift.png"));
	_textureBank.push_back(*IOManager::loadTextureFromFile("shelfFront.png"));
	_textureBank.push_back(*IOManager::loadTextureFromFile("shelfTopDown.png"));
}


TextureManager::~TextureManager()
{
}

sf::Texture * TextureManager::getTexture(string name)
{
	if (name=="box")
		return &_textureBank.at(0);
	else if (name == "floor")
		return &_textureBank.at(1);
	else if (name == "forklift")
		return &_textureBank.at(2);
	else if (name == "shelfFront")
		return &_textureBank.at(3);
	else if (name == "shelfTopDown")
		return &_textureBank.at(4);
	else
		ErrorHandler::errorMessage(ErrorHandler::WANT_NONEXIST_RESPONSE, "");

}
