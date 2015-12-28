#pragma once
#include <SFML\Graphics.hpp>
#include "Mechanic.h"
#include "GraphicsConfig.h"
#include "IOManager.h"
#include "TextureManager.h"

extern Mechanic * mechanic;

using namespace sf;
class FrontView
{
public:
	FrontView(TextureManager* TM, RenderWindow& window, int borderXAxis, int borderYAxis);
	~FrontView();
	void drawAllContent();
	void executeEvent(Vector2f& mouse, Event& event);

	void setActualShelf(Shelf* sh) { _actShelf = sh; }
	
private:
	void _drawMovableObjects();
	RenderWindow& _window;
	Shelf* _actShelf;
	int _borderXAxis;
	int _borderYAxis;

	Sprite* _background;
};

