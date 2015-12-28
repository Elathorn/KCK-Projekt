#include "GraphicManager.h"



GraphicManager::GraphicManager()
{
	TextureManager* TM = new TextureManager(); //stworzenie managera textur
	SI = new ScriptInterpreter();

	//stworzenie mechaniki i mapy
	mechanic->mapCreator(TM);

	//stworzenie okna i jego podzialu
	createWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
	BORDER_VIEWS_Y_AXIS = mechanic->findShelf("south")->getSprite()->getGlobalBounds().top
		+ mechanic->findShelf("south")->getSprite()->getGlobalBounds().height;
	BORDER_VIEWS_X_AXIS = mechanic->findShelf("east")->getSprite()->getGlobalBounds().left
		+ mechanic->findShelf("east")->getSprite()->getGlobalBounds().width;
	_frontView = new FrontView(TM, *_window, BORDER_VIEWS_X_AXIS, BORDER_VIEWS_Y_AXIS);
	_topView = new TopView(_frontView, TM, *_window, BORDER_VIEWS_X_AXIS, BORDER_VIEWS_Y_AXIS);
	_textBase = new TextBase(*_window, BORDER_VIEWS_X_AXIS);
	
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
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode == UNICODE_ENTER_CODE)
				{
					SI->interpretUserInput(_textBase->getLastLine());
				}
				else
				{
					_textBase->modifyTextByChar(event.text.unicode);
				}
			}
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
		_textBase->drawAllContent();
		//wyswietlanie
		_window->display();
	}
}

void GraphicManager::printCommunicate(string communicat)
{
	_textBase->addText(communicat);
}

string GraphicManager::getStringFromUser()
{
	return _textBase->getLastLine();
}

void GraphicManager::createWindow(int Xsize, int Ysize)
{
	_window = new RenderWindow(VideoMode(Xsize, Ysize), "KCK");
	_window->setFramerateLimit(60);
}

