#include "TopView.h"
#include "TextureManager.h"


TopView::TopView(FrontView* FV, TextureManager* TM, RenderWindow& window, Mechanic* mech, int borderXAxis, int borderYAxis) : _window(window)
{
	_mech = mech;
	_background = new Sprite(*TM->getTexture("floor"), IntRect(10, 10, borderXAxis, borderYAxis));
	_vec = _mech->getShelvesVec();
	_FV = FV;
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
		if (sprite->getGlobalBounds().contains(mouse)) //jezeli ktoras z polek jest wskazana
		{
			sprite->setColor(Color(200, 200, 200, 200));
			_FV->setActualShelf(*it); //zmieniamy aktualnie wyswietlana polke
		}
		else
			sprite->setColor(Color(255, 255, 255, 255)); //w innym wypadku
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

