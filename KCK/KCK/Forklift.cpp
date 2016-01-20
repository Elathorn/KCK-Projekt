#include "Forklift.h"
#include "TextureManager.h"
#include "Mechanic.h"

#define FORKLIFT_SCALE 0.22

using namespace sf;

Forklift::Forklift(RenderWindow& wind, TextureManager * TM) : _window(wind)
{
	_TM = TM;
	_sprite = new Sprite();
	setTexture(_TM->getTexture("forklift"));
	_sprite->setOrigin(
		_sprite->getGlobalBounds().width / 2,
		_sprite->getGlobalBounds().height / 2);
	_sprite->setPosition(Mechanic::MAP_X_SIZE*GRID_TO_WINDOW_RATIO/2, Mechanic::MAP_Y_SIZE*GRID_TO_WINDOW_RATIO/2);
	_sprite->setScale(FORKLIFT_SCALE, FORKLIFT_SCALE);
}


Forklift::~Forklift()
{
}


void Forklift::drawAllContent()
{
	int time = 50;
	sf::Vector2f vector = sf::Vector2f(_animationVector.x / time, _animationVector.y / time);
	if (_animationVector.x == 0 && _animationVector.y == 0)
		_animationIterator = 0;
	else
	{
		if (_animationIterator <= time)
		{
			_sprite->move(vector);
			_animationIterator++;
		}
		if (_animationIterator > time)
		{
			_animationIterator = 0;
			_animationVector.x = 0;
			_animationVector.y = 0;
		}
	}
	_window.draw(*_sprite);
	
}

void Forklift::prepareDataForAnimation(string endPos)
{
	if (endPos == "")
	{
		_animationVector = sf::Vector2f(0, 0);
		return;
	}
	sf::Vector2f startPos = this->getSprite()->getPosition();
	int endXPos, endYPos;
	if (endPos == "east") { endXPos = 397; endYPos = 237; }
	if (endPos == "north") { endXPos = 237; endYPos = 87; }
	if (endPos == "west") { endXPos = 87; endYPos = 237; }
	if (endPos == "south") { endXPos = 237; endYPos = 397; }
	float startXPos = startPos.x;
	float startYPos = startPos.y;
	float deltaX = endXPos - startXPos;
	float deltaY = endYPos - startYPos;
	if (endPos == "") { deltaX = 0; deltaY= 0; }
	sf::Vector2f finalVector = sf::Vector2f(deltaX, deltaY);
	_animationVector = finalVector;
	return;
}


