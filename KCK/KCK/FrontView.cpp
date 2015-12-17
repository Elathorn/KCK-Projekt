#include "FrontView.h"





FrontView::FrontView(RenderWindow & window, Mechanic * mech, int borderXAxis, int borderYAxis) : _window(window)
{
	_mech = mech;
	_borderXAxis = borderXAxis;
	_borderYAxis = borderYAxis;
	_background = new Sprite(*IOManager::loadSpriteFromFile("shelfFront.png"));
	_background->setPosition(borderXAxis, 0);
	_background->setScale(0.55, 0.55);
}

FrontView::~FrontView()
{
}

void FrontView::drawAllContent()
{
	_window.draw(*_background);
}

void FrontView::executeEvent(Vector2f & mouse, Event & event)
{

}
