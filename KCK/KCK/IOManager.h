#pragma once
#include "ErrorHandler.h"

#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class IOManager
{
public:
	static vector<string>* loadVectorFromFile(string); //wczytuje liste z pliku o okreslonej nazwie i zwraca wskaünik
	static map<string, string>* loadMapFromFile(string);
private:

public: //magic numbers
	static const string DATA_FILES_LOCATION;
	static const char WORD_SEPARATOR = ';';
};

