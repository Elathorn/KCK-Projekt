#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "ScriptInterpreter.h"
#include "TopView.h"
#include "TextView.h"
#include "FrontView.h"
using namespace std;
using namespace sf;
class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	void runGraphic(); //todo: grafika, lul
	static void printCommunicate(string communicat);
	static string getStringFromUser();

	

private:
	ScriptInterpreter* _SI;
	Mechanic* _mech; //todo: zmieniæ to jakoœ?
	RenderWindow* _window;
	TopView* _topView;
	FrontView* _frontView;
	TextBase* _textBase;
	void createWindow(int Xsize, int Ysize);

	


	int BORDER_VIEWS_X_AXIS; //granica pomiedzy widokiem z gory a dolu
	int BORDER_VIEWS_Y_AXIS; //granica pomiedzy oknem dialogowym a grafika

};

