#include "ScriptInterpreter.h"
#include "GraphicManager.h"

extern NaturalInterpreter * NI;
extern ScriptInterpreter * SI;
extern GraphicManager * GM;
extern Mechanic * mechanic;

ScriptInterpreter::ScriptInterpreter()
{
	mechanic = new Mechanic(); //tworzenie mechaniki
	NI = new NaturalInterpreter(); //i interpretera jezyka naturalnego
	_shelfNotFoundTxt = IOManager::loadVectorFromFile("shelfNotFound.txt");
	_movableObjNotFoundTxt = IOManager::loadVectorFromFile("movableObjectNotFound.txt");
	_shelfIsFullTxt = IOManager::loadVectorFromFile("shelfIsFull.txt");
	_commandNotUnderstandedTxt = IOManager::loadVectorFromFile("commandNotUnderstanded.txt");
	_goOrderDoneTxt = IOManager::loadVectorFromFile("goOrderDone.txt");
	_rackNotFoundTxt = IOManager::loadVectorFromFile("rackNotFound.txt");
	_objectIsActuallyHereTxt = IOManager::loadVectorFromFile("objectIsActuallyHere.txt");
	srand(time(NULL));
}

ScriptInterpreter::~ScriptInterpreter()
{

}

string ScriptInterpreter::interpretUserInput(string humanInput)
{
	vector<string>* script = NI->recognizeOrder(humanInput);

	//sprawdzenie istnienia rozkazu
	if (script->at(order) == "")
		checkValide(order, script);
	if (script->at(order) == "go")
	{
		checkValide(colorOfMovableObject + lvlOfShelf + adjToShelf, script); //WALIDACJA POTRZEBNYCH DANYCH
		Shelf* shelf = mechanic->findShelf(script->at(adjToShelf));
		MovableObject* obj = obj = mechanic->findMovableObject(script->at(colorOfMovableObject));
		char lvlOfShelfChar = script->at(lvlOfShelf)[0];
		MovableObject* objAtTargetShelf = shelf->getShelf(lvlOfShelfChar); //obiekt ktory moze byc na polce na ktora przenosimy
		delete script;
		if (objAtTargetShelf == obj) //jesli ten obiekt jest juz na tej polce
			return randomizeAnswer(objectIsActuallyHere); //informujemy o tym uzytkownika
		else if (mechanic->moveObject(shelf, obj, lvlOfShelfChar)) //jezeli NIE udalo sie przeniesc obiektu (pelna polka)
			return randomizeAnswer(shelfIsFull);
		else  //inaczej jesli sie udalo
			return randomizeAnswer(goOrderDone);

	}
	//else if (script->at[order] == "")

	//nie powinno sie nigdy zdarzyc, ale strzezonego...
	delete script;
	return randomizeAnswer(commandNotUnderstanded);
}

void ScriptInterpreter::checkValide(int enumSum, vector<string> * script)
{
		if (enumSum - colorOfMovableObject >= 0) //jesli roznica jest wieksza od zera
		{ //nalezy zwalidowac kolor obiektu
			MovableObject* obj = mechanic->findMovableObject(script->at(colorOfMovableObject));
			while (obj == nullptr)
			{
				GM->printCommunicate(randomizeAnswer(movableObjNotFound));
				script->at(colorOfMovableObject) = NI->searchForToken(movableObjNotFound);
				obj = mechanic->findMovableObject(script->at(colorOfMovableObject));
			}
			enumSum -= colorOfMovableObject;
		}
		if (enumSum - adjToShelf >= 0)
		{
			Shelf* shelf = mechanic->findShelf(script->at(adjToShelf));
			while (shelf == nullptr)
			{
				GM->printCommunicate(randomizeAnswer(shelfNotFound));
				script->at(adjToShelf) = NI->searchForToken(shelfNotFound);
				shelf = mechanic->findShelf(script->at(adjToShelf));
			}
			enumSum -= adjToShelf;
		}
		if (enumSum - lvlOfShelf >= 0)
		{
			while (script->at(lvlOfShelf) == "")
			{
				GM->printCommunicate(randomizeAnswer(rackNotFound));
				(*script)[lvlOfShelf] = NI->searchForToken(rackNotFound);
			}
			enumSum -= adjToShelf;
		} 
		if (enumSum - order >= 0)
		{
			while (script->at(order) == "")
			{
				GM->printCommunicate(randomizeAnswer(commandNotUnderstanded));
				script->at(order) = NI->searchForToken(commandNotUnderstanded);
			}
			enumSum -= order;
		}

}

string ScriptInterpreter::randomizeAnswer(int enumInt)
{
	switch (enumInt)
	{
	case (shelfNotFound) : return _shelfNotFoundTxt->at(randomNumber(_shelfNotFoundTxt->size()));break;
	case (movableObjNotFound) : return _movableObjNotFoundTxt->at(randomNumber(_movableObjNotFoundTxt->size()));break;
	case (shelfIsFull) : return _shelfIsFullTxt->at(randomNumber(_shelfIsFullTxt->size()));break;
	case (commandNotUnderstanded) : return _commandNotUnderstandedTxt->at(randomNumber(_commandNotUnderstandedTxt->size()));break;
	case (goOrderDone) : return _goOrderDoneTxt->at(randomNumber(_goOrderDoneTxt->size())); break;
	case (rackNotFound) : return _rackNotFoundTxt->at(randomNumber(_rackNotFoundTxt->size())); break;
	case (objectIsActuallyHere) : return _objectIsActuallyHereTxt->at(randomNumber(_objectIsActuallyHereTxt->size())); break;
	}

}

int ScriptInterpreter::randomNumber(int max)
{
	return rand() % max;
}

void ScriptInterpreter::run()
{
	string response = interpretUserInput(GM->getStringFromUser());
	GM->printCommunicate(response);
}