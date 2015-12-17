#pragma once
#include <SFML\Graphics.hpp>
#include "Mechanic.h"
#include "GraphicsConfig.h"
#include "IOManager.h"
using namespace sf;
class FrontView
{
public:
	FrontView(RenderWindow& window, Mechanic* mech, int borderXAxis, int borderYAxis);
	~FrontView();
	void drawAllContent();
	void executeEvent(Vector2f& mouse, Event& event);

private:
	RenderWindow& _window;
	Mechanic* _mech;

	int _borderXAxis;
	int _borderYAxis;

	Sprite* _background;
};

