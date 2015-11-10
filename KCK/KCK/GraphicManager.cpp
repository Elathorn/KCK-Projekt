#include "GraphicManager.h"



GraphicManager::GraphicManager()
{
	_SI = new ScriptInterpreter();
	_mech = _SI->getMechanic();
}


GraphicManager::~GraphicManager()
{
}

void GraphicManager::runGraphic()
{ //WSZYSTKO PONI¯EJ TYMCZASOWE I DO PRZENIESIENIA NA GRAFIKE, JEDYNE ZASTOSOWANIE TO TESTY AKTUALNEJ WERSJI!

	for (;;)
	{
		//* pêtla pokazuj¹ca rozmieszczenie pó³ek
		for (int x = Mechanic::MAP_X_SIZE - 1; x >= 0; x--)
		{
			for (int y = 0; y < Mechanic::MAP_Y_SIZE; y++)
			{
				cout << _mech->getGrid(x, y)->getGridType();
			}
			cout << endl;
		}
		//*/
		//cout << endl;
		cout << "Shelf: Top/Mid/Bottom" << endl;
		//WEST
		cout << "West: ";
		Shelf* sh = _mech->findShelf("west");
		if (sh->getTopShelf())
			cout << sh->getTopShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getMidShelf())
			cout << sh->getMidShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getBotShelf())
			cout << sh->getBotShelf()->getColor();
		else
			cout << "NULL";
		//EAST
		cout << endl << "East: ";
		sh = _mech->findShelf("east");
		if (sh->getTopShelf())
			cout << sh->getTopShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getMidShelf())
			cout << sh->getMidShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getBotShelf())
			cout << sh->getBotShelf()->getColor();
		else
			cout << "NULL";
		//NORTH
		cout << endl << "North: ";
		sh = _mech->findShelf("north");
		if (sh->getTopShelf())
			cout << sh->getTopShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getMidShelf())
			cout << sh->getMidShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getBotShelf())
			cout << sh->getBotShelf()->getColor();
		else
			cout << "NULL";
		//SOUTH
		cout << endl << "South: ";
		sh = _mech->findShelf("south");
		if (sh->getTopShelf())
			cout << sh->getTopShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getMidShelf())
			cout << sh->getMidShelf()->getColor();
		else
			cout << "NULL";
		cout << "/";
		if (sh->getBotShelf())
			cout << sh->getBotShelf()->getColor();
		else
			cout << "NULL";
		cout << endl;
		cout << "Podaj polecenie: ";
		string humanInput;
		getline(cin, humanInput);
		cout << _SI->interpretUserInput(humanInput);
		cout << endl << endl;
	}
	
}
