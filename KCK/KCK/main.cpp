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
	list<string>* tempList = new list<string>;
	tempList = IOManager::loadListFromFile("test.txt");
	for (list<string>::const_iterator i = tempList->begin(); i != tempList->end(); i++)
	{
		cout << *i;
	}

	tempList = IOManager::loadListFromFile("tes2t.txt");

	tempList = IOManager::loadListFromFile("t22est.txt");
	getchar();
	//end of sandbox

	return 0;
}

