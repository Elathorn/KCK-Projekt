#include "GraphicManager.h"



GraphicManager::GraphicManager()
{
	_SI = new ScriptInterpreter();
	_mech = _SI->getMechanic();
	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	BORDER_VIEWS_Y_AXIS = _mech->findShelf("south")->getSprite()->getGlobalBounds().top
		+ _mech->findShelf("south")->getSprite()->getGlobalBounds().height;
	BORDER_VIEWS_X_AXIS = _mech->findShelf("east")->getSprite()->getGlobalBounds().left
		+ _mech->findShelf("east")->getSprite()->getGlobalBounds().width;
	_topView = new TopView(*_window, _mech, BORDER_VIEWS_X_AXIS, BORDER_VIEWS_Y_AXIS);
	_frontView = new FrontView(*_window, _mech, BORDER_VIEWS_X_AXIS, BORDER_VIEWS_Y_AXIS);
}


GraphicManager::~GraphicManager()
{
}

void GraphicManager::runGraphic()
{ 
	while (_window->isOpen())
	{
		Vector2f mouse(Mouse::getPosition(*_window));
		Event event;
		while (_window->pollEvent(event))
		{
			//jesli event dzieje sie na terenie ktoregos z pol, tam go wysylamy
			//if (mouse.y > BORDER_VIEWS_Y_AXIS)

			//else
			if (mouse.x < BORDER_VIEWS_X_AXIS)
				_topView->executeEvent(mouse, event);
			else
				_frontView->executeEvent(mouse, event);
			if (event.type == Event::Closed)
				_window->close();

		}
		//czyszczenie
		_window->clear();
		//rysowanie
		
		_topView->drawAllContent();
		_frontView->drawAllContent();
		//wyswietlanie
		_window->display();
	}
}

void GraphicManager::printCommunicate(string communicat)
{
	cout << endl << communicat << endl;
}

string GraphicManager::getStringFromUser()
{
	string humanInput;
	getline(cin, humanInput);
	return humanInput;
}

void GraphicManager::createWindow(int Xsize, int Ysize)
{
	_window = new RenderWindow(VideoMode(Xsize, Ysize), "KCK");
	_window->setFramerateLimit(60);
}

