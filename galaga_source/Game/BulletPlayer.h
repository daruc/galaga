#pragma once
#include "Bullet.h"
#include <list>
#include "Enemy.h"
#include "GalagaGameScene.h"

class BulletPlayer :
	public Bullet
{
private:
	std::list<Enemy*>* enemies = NULL;
	void checkCollisionWithEnemy();
	std::list<Enemy*>* getEnemies();
	GalagaGameScene* getScene();
public:
	BulletPlayer(float speed);
	void update() override;
};

