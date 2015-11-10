#include "ScriptInterpreter.h"
#include "GraphicManager.h"



ScriptInterpreter::ScriptInterpreter()
{
	_mechanic = new Mechanic(); //tworzenie mechaniki
	_NI = new NaturalInterpreter(); //i interpretera jezyka naturalnego

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
	vector<string>* script = _NI->recognizeOrder(humanInput);
	enum scriptPart { order, adjToShelf, lvlOfShelf, colorOfMovableObject, sizeOfMovableObject };
	bool commandComplete = false;
	Shelf* shelf;
	MovableObject* obj;
	while (!commandComplete)
	{
		commandComplete = true;
		if (script->at(order) == "")
		{
			GraphicManager::printCommunicat(randomizeAnswer(commandNotUnderstanded)); //todo: metoda
			script->at(order) = _NI->searchForToken(commandNotUnderstanded);
			commandComplete = false;

		}
		shelf = _mechanic->findShelf(script->at(adjToShelf));
		if (shelf == NULL) //je?li nie znaleziono pó³ki
		{
			GraphicManager::printCommunicat(randomizeAnswer(shelfNotFound)); 
			script->at(adjToShelf) = _NI->searchForToken(shelfNotFound);
			commandComplete = false;
		}
		obj = _mechanic->findMovableObject(script->at(colorOfMovableObject), script->at(sizeOfMovableObject));
		if (obj == NULL) //je?li nie znaleziono obiektu
		{
			GraphicManager::printCommunicat(randomizeAnswer(movableObjNotFound));
			script->at(colorOfMovableObject) = _NI->searchForToken(movableObjNotFound); //todo: ogarn¹æ
			commandComplete = false;
		}
		if (script->at(lvlOfShelf) == "") //jesli nie istnieje lokalizator konkretnej polki (przegrodki)
		{
			GraphicManager::printCommunicat(randomizeAnswer(rackNotFound)); 
			(*script)[lvlOfShelf] = _NI->searchForToken(rackNotFound);
			commandComplete = false;
		}
	}

	char lvlOfShelfChar = script->at(lvlOfShelf)[0]; //konwersja stringa na chara - todo: cos nie tak
	MovableObject* objAtTargetShelf = shelf->getShelf(lvlOfShelfChar); //obiekt ktory moze byc na polce na ktora przenosimy


	if (script->at(order) == "go")
		if (objAtTargetShelf == obj) //jesli ten obiekt jest juz na tej polce
			return randomizeAnswer(objectIsActuallyHere); //informujemy o tym uzytkownika
		else if (_mechanic->moveObject(shelf, obj, lvlOfShelfChar)) //jezeli NIE udalo sie przeniesc obiektu (pelna polka)
			return randomizeAnswer(shelfIsFull);
		else  //inaczej jesli sie udalo
			return randomizeAnswer(goOrderDone);

	return randomizeAnswer(commandNotUnderstanded); //todo: wrzucic to do petli dialogowania
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
