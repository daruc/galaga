#pragma once
#include "Enemy.h"
#include "EnemyDirection.h"
#include "EnemyWithScore.h"
#include "EnemyWithSpeed.h"

class UnarmedEnemy :
	public Enemy, public EnemyWithScore, public EnemyWithSpeed
{
private:
	int score;

	float distanceToChangeDirection = 200.0f;
	float currentDistance = 0.0f;
	float horizontalSpeed; 
	float verticalSpeed;
	EnemyDirection direction = RIGHT;
	void setProperties() override;
public:
	void update() override;
	inline int getScore() override { return score; }
	void setSpeed(float horizontal, float vertical) override;
};

