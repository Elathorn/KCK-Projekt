#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Mechanic.h"
#include "IOManager.h"
using namespace std;
using namespace sf;

class TopView
{
public:
	TopView(RenderWindow& window, Mechanic* mech, int borderXAxis, int borderYAxis);
	~TopView();
	void drawAllContent();
	void executeEvent(Vector2f& mouse, Event& event);

private:
	RenderWindow& _window;
	Mechanic* _mech;
	void drawShelves();
	vector<Shelf*> _vec;
	Sprite* _background;
};

