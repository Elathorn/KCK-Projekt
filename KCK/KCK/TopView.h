#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Mechanic.h"
#include "IOManager.h"
#include "FrontView.h"
using namespace std;
using namespace sf;

class TopView
{
public:
	TopView(FrontView* FV, TextureManager* TM, RenderWindow& window, Mechanic* mech, int borderXAxis, int borderYAxis);
	~TopView();
	void drawAllContent();
	void executeEvent(Vector2f& mouse, Event& event);

private:
	RenderWindow& _window;
	Mechanic* _mech;
	void drawShelves();
	vector<Shelf*> _vec;
	Sprite* _background;
	FrontView* _FV; //front view
};

