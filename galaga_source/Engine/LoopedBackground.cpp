#include "LoopedBackground.h"

void LoopedBackground::moveToOppositeSideIfNecessary(sf::Sprite * sprite)
{
	float textureSize;
	switch (scrollingDirection)
	{
	case SCROLL_UP:
		textureSize = static_cast<float>(sprite->getTexture()->getSize().y);
		if (sprite->getPosition().y < -textureSize)
		{
			sprite->setPosition(0.f, textureSize);
		}
		break;
	case SCROLL_DOWN:
		if (sprite->getPosition().y > engine->getWindow()->getSize().y)
		{
			float textureSize = static_cast<float>(sprite->getTexture()->getSize().y);
			sprite->setPosition(0.f, -textureSize);
		}
		break;
	case SCROLL_LEFT:
		textureSize = static_cast<float>(sprite->getTexture()->getSize().x);
		if (sprite->getPosition().x < -textureSize)
		{
			sprite->setPosition(textureSize, 0.f);
		}
		break;
	case SCROLL_RIGHT:
		if (sprite->getPosition().x > engine->getWindow()->getSize().x)
		{
			float textureSize = static_cast<float>(sprite->getTexture()->getSize().x);
			sprite->setPosition(-textureSize, 0.f);
		}
		break;
	}
}

LoopedBackground::LoopedBackground(ScrollingDirection scrollingDirection, float scrollingSpeed)
	: scrollingDirection(scrollingDirection), scrollingSpeed(scrollingSpeed)
{
}

void LoopedBackground::setTexture(sf::Texture * texture)
{
	sprite1.setTexture(*texture);
	sprite2.setTexture(*texture);

	float textureSize;
	switch (scrollingDirection)
	{
	case SCROLL_UP:
		textureSize = static_cast<float>(texture->getSize().y);
		sprite2.setPosition(0.f, textureSize);
		break;
	case SCROLL_DOWN:
		textureSize = static_cast<float>(texture->getSize().y);
		sprite2.setPosition(0.f, -textureSize);
		break;
	case SCROLL_LEFT:
		textureSize = static_cast<float>(texture->getSize().x);
		sprite2.setPosition(textureSize, 0.f);
		break;
	case SCROLL_RIGHT:
		textureSize = static_cast<float>(texture->getSize().x);
		sprite2.setPosition(-textureSize, 0.f);
		break;
	}
}

void LoopedBackground::input()
{
}

void LoopedBackground::update()
{
	float deltaTime = engine->getElapsedTime().asSeconds();

	sf::Vector2f direction;
	switch (scrollingDirection)
	{
	case SCROLL_UP:
		direction.y = -1.f;
		break;
	case SCROLL_DOWN:
		direction.y = 1.f;
		break;
	case SCROLL_LEFT:
		direction.x = -1.f;
		break;
	case SCROLL_RIGHT:
		direction.x = 1.f;
		break;
	}
	

	sf::Vector2f replacement = direction * deltaTime * scrollingSpeed;

	sf::Vector2f previousPosition1 = sprite1.getPosition();
	sf::Vector2f previousPosition2 = sprite2.getPosition();

	sf::Vector2f newPosition1 = previousPosition1 + replacement;
	sf::Vector2f newPosition2 = previousPosition2 + replacement;

	sprite1.setPosition(newPosition1);
	sprite2.setPosition(newPosition2);

	moveToOppositeSideIfNecessary(&sprite1);
	moveToOppositeSideIfNecessary(&sprite2);
}

void LoopedBackground::draw()
{
	engine->getWindow()->draw(sprite1);
	engine->getWindow()->draw(sprite2);
}