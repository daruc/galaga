#include "BulletPlayer.h"
#include "GameScene.h"
#include "EnemyWithScore.h"

void BulletPlayer::checkCollisionWithEnemy()
{
	std::list<Enemy*>* enemies = getEnemies();
	for (Enemy* enemy : *enemies)
	{
		if (intersects(enemy)) {
			enemy->remove();
			remove();
			GalagaGameScene* gameScene = getScene();
			gameScene->decrementEnemiesLeft(dynamic_cast<EnemyWithScore*>(enemy)->getScore());
		}
	}
}

std::list<Enemy*>* BulletPlayer::getEnemies()
{
	if (enemies == NULL)
	{
		GameScene* gameScene = dynamic_cast<GameScene*>(engine->getCurrentScene());
		enemies = gameScene->getEnemies();
	}
	return enemies;
}

GalagaGameScene * BulletPlayer::getScene()
{
	return dynamic_cast<GalagaGameScene*>(engine->getCurrentScene());
}

BulletPlayer::BulletPlayer(float speed)
	: Bullet(speed, sf::Vector2f(0.f, -1.f))
{
}

void BulletPlayer::update()
{
	Bullet::update();
	checkCollisionWithEnemy();
	if (!isReadyToRemove() && sprite.getPosition().y < 0.f)
	{
		remove();
	}
}
