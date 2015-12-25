#include "GraphicManager.h"



GraphicManager::GraphicManager()
{
	TextureManager* TM = new TextureManager(); //stworzenie managera textur
	_SI = new ScriptInterpreter();

	//stworzenie mechaniki i mapy
	_mech = _SI->getMechanic();
	_mech->mapCreator(TM);

	//stworzenie okna i jego podzialu
	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	BORDER_VIEWS_Y_AXIS = _mech->findShelf("south")->getSprite()->getGlobalBounds().top
		+ _mech->findShelf("south")->getSprite()->getGlobalBounds().height;
	BORDER_VIEWS_X_AXIS = _mech->findShelf("east")->getSprite()->getGlobalBounds().left
		+ _mech->findShelf("east")->getSprite()->getGlobalBounds().width;
	_frontView = new FrontView(TM, *_window, _mech, BORDER_VIEWS_X_AXIS, BORDER_VIEWS_Y_AXIS);
	_topView = new TopView(_frontView, TM, *_window, _mech, BORDER_VIEWS_X_AXIS, BORDER_VIEWS_Y_AXIS);
	_textView = new TextView(*_window, BORDER_VIEWS_X_AXIS);
	
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
		_textView->drawAllContent();
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

