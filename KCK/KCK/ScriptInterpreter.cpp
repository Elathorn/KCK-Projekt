#include "ScriptInterpreter.h"
#include "GraphicManager.h"

extern NaturalInterpreter * NI;
extern ScriptInterpreter * SI;
extern GraphicManager * GM;
extern Mechanic * mechanic;

string strReplace(string str, string formatSpec, string replace)
{
    size_t pos;
    pos = str.find(formatSpec);
    str.replace(pos, formatSpec.length(), replace);
    return str;
}
/*
string strReplace(string str, string formatSpec, string replace) 
{
    //przygotowanie buffora na ktorym bedziemy dzialac
    const int bufforSize = str.length() + replace.length() - formatSpec.length();
    char * buff = new char[bufforSize];
    std::copy(str.begin(), str.end(), buff);
    buff[str.size()] = '\0';

    //aktualna podmiana
    sprintf(buff, buff, replace);

    //wracamy do C++ stringa
    str = buff;
    return str;
}*/

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
    _whatResponseEmptyTxt = IOManager::loadVectorFromFile("whatResponseEmpty.txt");
    _whatResponseFullTxt = IOManager::loadVectorFromFile("whatResponseFull.txt");
    _hiResponseTxt = IOManager::loadVectorFromFile("hiResponse.txt");
    _endTxt = IOManager::loadVectorFromFile("end.txt");
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
		checkValidation(order, script);
	if (script->at(order) == "go")
	{
		checkValidation(colorOfMovableObject + lvlOfShelf + adjToShelf, script); //WALIDACJA POTRZEBNYCH DANYCH
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
	} else if (script->at(order) == "what")
    {
        checkValidation(adjToShelf, script);
        Shelf* shelf = mechanic->findShelf(script->at(adjToShelf)); //znajdujemy polke na ktorej mamy dzialac
        string rp[3]; //trzy skladowe odpowiedzi
        for (int i = 0; i < 3; i++)
        {
            MovableObject * obj;
            if ((obj = shelf->getShelf(i)) == NULL)
                rp[i] = strReplace(randomizeAnswer(WhatResponseEmpty), "%s", shelf->getShelfName(i));
            else
            {
                rp[i] = strReplace(randomizeAnswer(WhatResponseFull), "%s", shelf->getShelfName(i));
                rp[i] = strReplace(rp[i], "%o", obj->getColorPL());
            }
        }
        delete script;
        return rp[0] + rp[1] + rp[2];
    } else if (script->at(order) == "hi")
    {
        delete script;
        return randomizeAnswer(HiResponse);
    } else if (script->at(order) == "end")
    {
        delete script;
        GM->printCommunicate(randomizeAnswer(End));
        GM->stopGraphic(5);
       // return "";
    }
	//else if (script->at[order] == "")

	//nie powinno sie nigdy zdarzyc, ale strzezonego...
	delete script;
	return randomizeAnswer(commandNotUnderstanded);

}

void ScriptInterpreter::checkValidation(int enumSum, vector<string> * script)
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
    case (WhatResponseEmpty) : return _whatResponseEmptyTxt->at(randomNumber(_whatResponseEmptyTxt->size())); break;
    case (WhatResponseFull) : return _whatResponseFullTxt->at(randomNumber(_whatResponseFullTxt->size())); break;
    case (HiResponse) : return _hiResponseTxt->at(randomNumber(_hiResponseTxt->size())); break;
    case(End) : return _endTxt->at(randomNumber(_endTxt->size()));
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