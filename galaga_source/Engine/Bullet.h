#pragma once
#include "InteractiveObject.h"
class Bullet :
	public InteractiveObject
{
private:
	sf::Vector2f direction;
	float speed;	// px/s

public:
	Bullet(float speed, sf::Vector2f direction);
	void input() override;
	void update() override;
};

