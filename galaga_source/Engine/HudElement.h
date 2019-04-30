#pragma once
#include "Engine.h"

class HudElement
{
protected:
	Engine * engine;
public:
	inline void setEngine(Engine * engine) { this->engine = engine; }
	virtual void input(sf::Event * event) = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

