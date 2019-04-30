#pragma once
#include <Bullet.h>
#include "Player.h"

class BulletEnemy :
	public Bullet
{
private:
	Player * player = NULL;
	void checkCollisionWithPlayer();
	Player * getPlayer();
public:
	BulletEnemy(float speed);
	void update() override;
};

