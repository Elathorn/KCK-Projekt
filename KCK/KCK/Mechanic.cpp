#include "Mechanic.h"
#include "GraphicManager.h"
extern GraphicManager * GM;

Mechanic::Mechanic()
{
	_emptyGrid = new Grid();
	for (int x = MAP_X_SIZE-1; x >= 0; x--)
	{
		for (int y = 0; y < MAP_Y_SIZE; y++)
			_map[x][y] = _emptyGrid; //wype�nienie ca�ej mapy pustk�
	}
}


Mechanic::~Mechanic()
{

}

int Mechanic::moveObject(Shelf* newShelf, MovableObject * movableObject, char shelfLvl)
{
	//bierzemy lokalizacje pude�ka (a wi�c i shelfa), nast�pnie z mapy bierzemy shelfa i rzutujemy go na jego klase
	Shelf* oldShelf = dynamic_cast<Shelf*>(_map[movableObject->getLocationXAxis()][movableObject->getLocationYAxis()]);
	if (oldShelf == NULL) //je�li wybrany grid jakim� cudem nie jest p�k�
	{
		ErrorHandler::errorMessage(ErrorHandler::GRID_IS_NOT_A_SHELF, "");
		return 0;
	}
	if (newShelf->getShelf(shelfLvl) != NULL)//sprawdzenie, czy nowy p�ka nie jest pe�na
		return SHELF_IS_FULL;
	oldShelf->setShelf(NULL,(oldShelf->searchShelves(movableObject))); //usuni�cie pude�ka z starej lokalizacji
	movableObject->move(newShelf->getLocationX(), newShelf->getLocationY()); //zmieniamy koordytany obiektu (pude�ka)
	newShelf->setShelf(movableObject, shelfLvl); //dodajemy pude�ko na nowej lokalizacji
	return 0;
}

MovableObject * Mechanic::findMovableObject(string color)
{
	for (auto & it : _movableObjectsVec)
	{ //szuka przedmiotu o takim samym kolorze i rozmiarze
		if (color == it->getColor())
			return it;
	}
	return NULL;
}

Shelf * Mechanic::findShelf(string locationStr)
{
	int locationX, locationY;
	if( GM != NULL)
		GM->_forklift->prepareDataForAnimation(locationStr);
	if (locationStr == "north") //je�li lokalizacja to p�noc
	{
		locationY = 0; //to ustawiamy jej warto��
		locationX = MAP_X_SIZE / 2; //atm warto�ci s� sta�e w stosunku do mapy
	}
	else if (locationStr == "south")
	{
		locationY = MAP_Y_SIZE - 1;
		locationX = MAP_X_SIZE / 2;
	}
	else if (locationStr == "east")
	{
		locationY = MAP_Y_SIZE / 2;
		locationX = MAP_X_SIZE-1;
	}
	else if (locationStr == "west")
	{
		locationY = MAP_Y_SIZE / 2;
		locationX = 0;
	}
	else return NULL;
	for (auto & it : _shelvesVec) //szukamy wszystkich p�ek
	{
		if (it->getLocationX() == locationX && it->getLocationY() == locationY)//i zwracamy t�, kt�ra jest w po��danej lokalizacji
			return it;
	}
	return NULL;
}

Grid * Mechanic::getGrid(int locX, int locY)
{
	if (locX >= MAP_X_SIZE || locX < 0 || locY < 0 || locY >= MAP_Y_SIZE) //zabezpieczenie przez wyj�ciem poza tablice
		return nullptr;
	else
		return _map[locY][locX];
}

void Mechanic::mapCreator(TextureManager* TM)
{
	//pierwszy obiekt i pierwsza p�ka
	MovableObject* obj;
	obj = new MovableObject(TM, MAP_X_SIZE - 1, MAP_Y_SIZE / 2, "red", "big"); //tworzymy przedmiot
	_movableObjectsVec.push_back(obj); //dodajemy go do listy przedmiot�w
	Grid* shelf; 
	shelf = new Shelf(TM, MAP_X_SIZE - 1, MAP_Y_SIZE / 2, obj, NULL, NULL); //tworzymy szafk�, na kt�r� wk�adamy przedmiot
	_map[MAP_X_SIZE - 1][MAP_Y_SIZE / 2] = shelf; //umieszczamy szafk� (jeszcze jako grid) na mapie
	Shelf* shelf2 = dynamic_cast<Shelf*>(shelf); //rzutujemy na jej bazow� klase
	_shelvesVec.push_back(shelf2); //i dodajemy do listy szafek
	
	//drugi obiekt i druga p�ka
	obj = new MovableObject(TM, 0, MAP_Y_SIZE / 2, "green", "small");
	_movableObjectsVec.push_back(obj);
	shelf = new Shelf(TM, 0, MAP_Y_SIZE / 2, obj, NULL, NULL);
	_map[0][MAP_Y_SIZE / 2] = shelf;
	shelf2 = dynamic_cast<Shelf*>(shelf);
	_shelvesVec.push_back(shelf2);
	
	//trzeci obiekt i trzecia p�ka
	obj = new MovableObject(TM, MAP_X_SIZE / 2, 0,  "blue", "small");
	_movableObjectsVec.push_back(obj);
	shelf = new Shelf(TM, MAP_X_SIZE / 2, 0, NULL, NULL, obj);
	_map[MAP_X_SIZE/2][0] = shelf;
	shelf2 = dynamic_cast<Shelf*>(shelf);
	_shelvesVec.push_back(shelf2);

	//czwarty obiekt i czwarta p�ka
	obj = new MovableObject(TM, MAP_X_SIZE / 2, MAP_Y_SIZE - 1, "yellow", "big");
	_movableObjectsVec.push_back(obj);
	shelf = new Shelf(TM, MAP_X_SIZE / 2, MAP_Y_SIZE - 1, NULL, obj, NULL);
	_map[MAP_X_SIZE / 2][MAP_Y_SIZE - 1] = shelf;
	shelf2 = dynamic_cast<Shelf*>(shelf);
	_shelvesVec.push_back(shelf2);

	//pi�ty obiekt
	obj = new MovableObject(TM, MAP_X_SIZE / 2, MAP_Y_SIZE - 1, "white", "big");
	_movableObjectsVec.push_back(obj);
	shelf2->setTopShelf(obj);

}
