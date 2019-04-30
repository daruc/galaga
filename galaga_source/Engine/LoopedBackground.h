#pragma once
#include <SFML/Graphics.hpp>
#include "InteractiveBackground.h"

enum ScrollingDirection
{
	SCROLL_UP, SCROLL_DOWN, SCROLL_LEFT, SCROLL_RIGHT
};

class LoopedBackground : public InteractiveBackground
{
private:
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	ScrollingDirection scrollingDirection;
	float scrollingSpeed; // px/s

	void moveToOppositeSideIfNecessary(sf::Sprite * sprite);
public:
	LoopedBackground(ScrollingDirection scrollingDirection, float scrollingSpeed);
	void setTexture(sf::Texture * texture);
	void input() override;
	void update() override;
	void draw() override;
};
