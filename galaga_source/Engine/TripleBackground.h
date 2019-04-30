#pragma once
#include "InteractiveBackground.h"
#include "LoopedBackground.h"

class TripleBackground :
	public InteractiveBackground
{
private:
	LoopedBackground background1;
	LoopedBackground background2;
	LoopedBackground background3;
public:
	TripleBackground(ScrollingDirection scrollingDirection, float scrollingSpeed1, float scrollingSpeed2, float scrollingSpeed3);
	void setTexture(int number, sf::Texture * texture);
	void input();
	void update();
	void draw();
	void setEngine(Engine * engine) override;
};

