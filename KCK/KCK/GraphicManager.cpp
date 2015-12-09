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
	}
	//czyszczenie
	_window->clear();
	//rysowanie

	//wyswietlanie
	_window->display();
}

void GraphicManager::printCommunicat(string communicat)
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

void GraphicManager::printObjectsFromVector(RenderWindow & window, Event event, vector<GraphicObject> vec)
{
	for (vector<GraphicObject>::iterator it = vec.begin(); it != vec.end(); ++it) //iterujemy przez caly vector
	{
		Sprite* sprite = (*it)->getSprite();
	}
}

