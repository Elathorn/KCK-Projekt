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
	_window.draw(*_sprite);
}
