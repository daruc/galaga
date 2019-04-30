#include "InteractiveObject.h"

void InteractiveObject::setTexture(sf::Texture * texture)
{
	sprite.setTexture(*texture);
}

void InteractiveObject::setEngine(Engine * engine)
{
	this->engine = engine;
	setProperties();
}

void InteractiveObject::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void InteractiveObject::draw()
{
	engine->getWindow()->draw(sprite);
}

bool InteractiveObject::intersects(InteractiveObject * other)
{
	return sprite.getGlobalBounds().intersects(other->sprite.getGlobalBounds());
}