#pragma once
#include "GraphicManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "ScriptInterpreter.h"
#include "GraphicsConfig.h"
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
	Mechanic* _mech; //todo: zmieni� to jako�?
	RenderWindow* _window;
	

	void createWindow(int Xsize, int Ysize);

	void drawShelves();

};

