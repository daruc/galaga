#include "TripleBackground.h"

TripleBackground::TripleBackground(ScrollingDirection scrollingDirection, float scrollingSpeed1, float scrollingSpeed2, float scrollingSpeed3)
	: background1(scrollingDirection, scrollingSpeed1),
	background2(scrollingDirection, scrollingSpeed2),
	background3(scrollingDirection, scrollingSpeed3)
{
}

void TripleBackground::setTexture(int number, sf::Texture * texture)
{
	switch (number)
	{
	case 1:
		background1.setTexture(texture);
		break;
	case 2:
		background2.setTexture(texture);
		break;
	case 3:
		background3.setTexture(texture);
		break;
	}
}

void TripleBackground::input()
{
	background3.input();
	background2.input();
	background1.input();
}

void TripleBackground::update()
{
	background3.update();
	background2.update();
	background1.update();
}

void TripleBackground::draw()
{
	background3.draw();
	background2.draw();
	background1.draw();
}

void TripleBackground::setEngine(Engine * engine)
{
	background1.setEngine(engine);
	background2.setEngine(engine);
	background3.setEngine(engine);
}
