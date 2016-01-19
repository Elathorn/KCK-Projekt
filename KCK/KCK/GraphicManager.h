#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "ScriptInterpreter.h"
#include "TopView.h"
#include "TextView.h"
#include "FrontView.h"
#include "Forklift.h"

extern ScriptInterpreter * SI;


using namespace std;
using namespace sf;
class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	void runGraphic(); //todo: grafika, lul
	void printCommunicate(string communicat);
	string getStringFromUser();
    void stopGraphic(int time);
	

private:
	RenderWindow* _window;
	TopView* _topView;
	FrontView* _frontView;
	TextBase* _textBase;
	Forklift* _forklift;
	void createWindow(int Xsize, int Ysize);

	

	static const int UNICODE_ENTER_CODE = 13;
	int BORDER_VIEWS_X_AXIS; //granica pomiedzy widokiem z gory a dolu
	int BORDER_VIEWS_Y_AXIS; //granica pomiedzy oknem dialogowym a grafika

};

