#include "Bullet.h"

Bullet::Bullet(float speed, sf::Vector2f direction)
	: speed(speed), direction(direction)
{
}

void Bullet::input()
{
}

void Bullet::update()
{
	float deltaTime = engine->getElapsedTime().asSeconds();
	sf::Vector2f replacement = direction * speed * deltaTime;
	sf::Vector2f previousPosition = sprite.getPosition();
	sf::Vector2f nextPosition = previousPosition + replacement;
	sprite.setPosition(nextPosition);
}
