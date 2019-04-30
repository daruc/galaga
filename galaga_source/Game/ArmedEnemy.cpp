#include "ArmedEnemy.h"
#include "GameScene.h"
#include "BulletEnemy.h"
#include "GalagaGameScene.h"
#include "utils.h"


void ArmedEnemy::shoot()
{
	GameScene* gameScene = dynamic_cast<GameScene *>(engine->getCurrentScene());
	BulletEnemy* bullet = new BulletEnemy(bulletSpeed);

	sf::Vector2f position = sprite.getPosition();
	bullet->setPosition(position.x + 28.f, position.y + 30.f);

	sf::Texture* texture = gameScene->getTexture("Assets/Graphics/Bullet.png");
	bullet->setTexture(texture);

	gameScene->addBullet(bullet);
}

void ArmedEnemy::update()
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

	currentCooldown -= deltaTime;
	if (currentCooldown < 0.f)
	{
		currentCooldown = 0.f;
	}
	if (currentCooldown == 0.f)
	{
		shoot();
		currentCooldown = cooldown;
	}

	if (newPosition.y > 400.0f)
	{
		GalagaGameScene* galagaGameScene = dynamic_cast<GalagaGameScene*>(engine->getCurrentScene());
		remove();
		galagaGameScene->replayLevel();
	}
}

void ArmedEnemy::setSpeed(float horizontal, float vertical)
{
	horizontalSpeed = horizontal;
	verticalSpeed = vertical;
}

void ArmedEnemy::setProperties()
{
	Properties * properties = engine->getProperties();

	float cooldownRangeLeft = properties->get<float>("enemy.armed.cooldown.range.left");
	float cooldownRangeRight = properties->get<float>("enemy.armed.cooldown.range.right");

	cooldown = randRange(cooldownRangeLeft, cooldownRangeRight);
	currentCooldown = cooldown;

	score = properties->get<int>("enemy.armed.baseScore");
	bulletSpeed = properties->get<float>("enemy.armed.bulletSpeed");
}
