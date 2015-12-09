#include "GraphicManager.h"



GraphicManager::GraphicManager()
{
	_SI = new ScriptInterpreter();
	_mech = _SI->getMechanic();
	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}


GraphicManager::~GraphicManager()
{
}

void GraphicManager::runGraphic()
{ 
	while (_window->isOpen())
	{
		Event event;
		while (_window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				_window->close();
		}
		//czyszczenie
		_window->clear();
		//rysowanie
		drawShelves();
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
}

void GraphicManager::drawShelves()
{
	vector<Shelf*> vec = _mech->getShelvesVec();
	for (vector<Shelf*>::iterator it = vec.begin(); it != vec.end(); ++it) //iterujemy przez caly vector
	{
		Sprite* sprite = (*it)->getSprite();
		_window->draw(*sprite);
	}
}

