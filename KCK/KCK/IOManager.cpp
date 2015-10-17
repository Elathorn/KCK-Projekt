#include "IOManager.h"

const string IOManager::DATA_FILES_LOCATION = "data/";

vector<string>* IOManager::loadVectorFromFile(string fileName)
{
	string location = DATA_FILES_LOCATION + fileName;
	ifstream in(location.c_str());
	if (in)
	{
		vector<string>* inputList = new vector<string>;
		string tmp;
		while (getline(in, tmp)) //wczytujemy wszystkie elementy listy
		{
			inputList->push_back(tmp);
		}
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
		while (getline(in, word, WORD_SEPARATOR)) //wczytujemy wszystkie elementy s�ownika, najpierw s�owo
		{
			getline(in, key); //nast�pnie klucz
			inputMap->insert({ word, key });
		}
		return inputMap;
	}
	else
	{
		ErrorHandler::errorMessage(ErrorHandler::FILE_FAILED_TO_LOAD, fileName);
	}

	return nullptr;
}
