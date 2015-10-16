#include "IOManager.h"

const string IOManager::DATA_FILES_LOCATION = "data/";

list<string>* IOManager::loadListFromFile(string fileName)
{
	string location = DATA_FILES_LOCATION + fileName;
	ifstream in(location.c_str());
	if (in)
	{
		list<string>* inputList = new list<string>;
		string tmp;
		while (getline(in, tmp, WORD_SEPARATOR)) //wczytujemy wszystkie elementy listy
			inputList->push_back(tmp);
		return inputList;
	}
	else
	{
		ErrorHandler::errorMessage(ErrorHandler::FILE_FAILED_TO_LOAD, fileName);
	}

	return nullptr;
}

map<string, string>* IOManager::loadMapFromFile(string fileName)
{
	string location = DATA_FILES_LOCATION + fileName;
	ifstream in(location.c_str());
	if (in)
	{
		map<string, string>* inputMap = new map<string,string>;
		string key, word;
		while (getline(in, word, WORD_SEPARATOR)) //wczytujemy wszystkie elementy s³ownika, najpierw s³owo
		{
			getline(in, key, WORD_SEPARATOR); //nastêpnie klucz
			inputMap->insert({ key, word });
		}
		return inputMap;
	}
	else
	{
		ErrorHandler::errorMessage(ErrorHandler::FILE_FAILED_TO_LOAD, fileName);
	}

	return nullptr;
}
