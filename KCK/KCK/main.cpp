//////////////////
//Projekt KCK
//G�azik Micha�
//Hliwa Kamil
//
//W�zek wid�owy
//////////////////

#include "IOManager.h"

#include <iostream>
using namespace std;

int main()
{



	//sandbox 
	map<string, string>* myMap;
	myMap = IOManager::loadMapFromFile("test.txt");
	for (auto elem : *myMap)
	{
		std::cout << elem.first << " " << elem.second << "\n";
	}
	getchar();
	//end of sandbox

	return 0; //test
}

