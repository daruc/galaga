#include "BulletEnemy.h"
#include "GameScene.h"
#include "GalagaGameScene.h"


void BulletEnemy::checkCollisionWithPlayer()
{
	if (intersects(getPlayer()))
	{
		GalagaGameScene* galagaGameScene = dynamic_cast<GalagaGameScene*>(engine->getCurrentScene());
		remove();
		galagaGameScene->replayLevel();
	}
}

Player * BulletEnemy::getPlayer()
{
	if (player == NULL)
	{
		GameScene* gameScene = dynamic_cast<GameScene*>(engine->getCurrentScene());
		player = gameScene->getPlayer();
	}
	return player;
}

BulletEnemy::BulletEnemy(float speed)
	: Bullet(speed, sf::Vector2f(0.f, 1.f))
{
}

void BulletEnemy::update()
{
	Bullet::update();
	checkCollisionWithPlayer();
	if (!isReadyToRemove() && sprite.getPosition().y < 0.f)
	{
		remove();
	}
}
