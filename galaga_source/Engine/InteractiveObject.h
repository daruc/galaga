#pragma once
#include "Engine.h"

class InteractiveObject
{
private:
	bool readyToRemove = false;
protected:
	sf::Sprite sprite;
	Engine * engine;
	virtual void setProperties() {};
public:
	void setTexture(sf::Texture * texture);
	void setEngine(Engine * engine);
	void setPosition(float x, float y);
	virtual void input() = 0;
	virtual void update() = 0;
	void draw();
	inline bool isReadyToRemove() { return readyToRemove; }
	inline void remove() { readyToRemove = true; }
	bool intersects(InteractiveObject * other);
};

