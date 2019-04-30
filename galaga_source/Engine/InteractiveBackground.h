#pragma once
#include "Engine.h"

class InteractiveBackground
{
protected:
	Engine * engine;
public:
	virtual void input() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void setEngine(Engine * engine);
};

