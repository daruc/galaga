#include "ShipPlayer.h"
#include <cmath>
#include "GameScene.h"
#include "BulletPlayer.h"

void ShipPlayer::shoot()
{
	GameScene* gameScene = dynamic_cast<GameScene *>(engine->getCurrentScene());
	BulletPlayer* bullet = new BulletPlayer(bulletSpeed);

	sf::Vector2f position = sprite.getPosition();
	bullet->setPosition(position.x + 28.f, position.y - 18.f);

	sf::Texture* texture = gameScene->getTexture("Assets/Graphics/Bullet.png");
	bullet->setTexture(texture);

	gameScene->addBullet(bullet);
}

void ShipPlayer::setProperties()
{
	Properties * prop = engine->getProperties();
	maxSpeed = prop->get<float>("player.maxSpeed");
	acceleration = prop->get<float>("player.acceleration");
	friction = prop->get<float>("player.friction");
	cooldown = prop->get<float>("player.cooldown");
	bulletSpeed = prop->get<float>("player.bulletSpeed");
}


void ShipPlayer::input()
{
	goLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	goRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	bShoot = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void ShipPlayer::update()
{
	float deltaTime = engine->getElapsedTime().asSeconds();

	if (cooldownProgress > 0.f)
	{
		cooldownProgress -= deltaTime;
		if (cooldownProgress < 0.f)
		{
			cooldownProgress = 0.f;
		}
	}

	if (bShoot && cooldownProgress == 0.f)
	{
		bShoot = false;
		cooldownProgress = cooldown;
		shoot();
	}

	if (goLeft && !goRight)
	{
		currentSpeed -= deltaTime * acceleration;
	}
	if (!goLeft && goRight)
	{
		currentSpeed += deltaTime * acceleration;
	}

	float frictionDelta = friction * deltaTime;
	if (!goRight && currentSpeed > 0.f)
	{
		if (currentSpeed > frictionDelta)
		{
			currentSpeed -= frictionDelta;
		}
		else
		{
			currentSpeed = 0.f;
		}
	}
	else if (!goLeft && currentSpeed < 0.f)
	{
		if (currentSpeed < frictionDelta)
		{
			currentSpeed += frictionDelta;
		}
		else
		{
			currentSpeed = 0.f;
		}
	}

	if (currentSpeed > maxSpeed)
	{
		currentSpeed = maxSpeed;
	}
	else if (currentSpeed < -maxSpeed)
	{
		currentSpeed = -maxSpeed;
	}

	sf::Vector2f replacement(currentSpeed * deltaTime, 0.f);
	sf::Vector2f previousPosition = sprite.getPosition();
	sf::Vector2f nextPosition = previousPosition + replacement;
	if (nextPosition.x >= MAX_X)
	{
		nextPosition.x = MAX_X;
	}
	else if (nextPosition.x <= 0)
	{
		nextPosition.x = 0;
	}
	sprite.setPosition(nextPosition);
}
