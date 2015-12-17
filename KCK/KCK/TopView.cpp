#include "TopView.h"



TopView::TopView(RenderWindow& window, Mechanic* mech, int borderXAxis, int borderYAxis) : _window(window)
{
	_mech = mech;
	_background = new Sprite(*IOManager::loadSpriteFromFile("floor.png"), IntRect(10, 10, borderXAxis, borderYAxis));
	_vec = _mech->getShelvesVec();
}



TopView::~TopView()
{
}

void TopView::drawAllContent()
{
	_window.draw(*_background);
	drawShelves();
}

void TopView::executeEvent(Vector2f& mouse, Event& event)
{
	//sprawdzanie czy ktoras z polek zawiera mysz
	for (vector<Shelf*>::iterator it = _vec.begin(); it != _vec.end(); ++it) //iterujemy przez caly vector
	{
		Sprite* sprite = (*it)->getSprite();
		//if (sprite->getGlobalBounds().contains(mouse))
		if (event.type == Event::MouseButtonPressed)
			sprite->setColor(Color(255, 255, 0, 255));
		else
			sprite->setColor(Color(0, 255, 0, 255));
	}
	return;
}

void TopView::drawShelves()
{
	for (vector<Shelf*>::iterator it = _vec.begin(); it != _vec.end(); ++it) //iterujemy przez caly vector
	{
		Sprite* sprite = (*it)->getSprite();
		_window.draw(*sprite);
	}
}

