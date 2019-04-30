#include "UnarmedEnemy.h"
#include "GalagaGameScene.h"


void UnarmedEnemy::setProperties()
{
	Properties * prop = engine->getProperties();
	score = prop->get<int>("enemy.unarmed.baseScore");
}

void UnarmedEnemy::update()
{
	float deltaTime = engine->getElapsedTime().asSeconds();
	sf::Vector2f replacement;

	float deltaDistance = horizontalSpeed * deltaTime;
	currentDistance += deltaDistance;
	if (currentDistance >= distanceToChangeDirection)
	{
		currentDistance = 0.f;
		if (direction == LEFT)
		{
			direction = RIGHT;
		}
		else
		{
			direction = LEFT;
		}
	}

	if (direction == LEFT)
	{
		replacement.x = -deltaDistance;
	}
	else
	{
		replacement.x = deltaDistance;
	}

	replacement.y += verticalSpeed * deltaTime;

	sf::Vector2f oldPosition = sprite.getPosition();
	sf::Vector2f newPosition = oldPosition + replacement;
	sprite.setPosition(newPosition);

	if (newPosition.y > 400.0f)
	{
		GalagaGameScene* galagaGameScene = dynamic_cast<GalagaGameScene*>(engine->getCurrentScene());
		remove();
		galagaGameScene->replayLevel();
	}
}

void UnarmedEnemy::setSpeed(float horizontal, float vertical)
{
	horizontalSpeed = horizontal;
	verticalSpeed = vertical;
}
