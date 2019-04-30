#pragma once
#include <Player.h>
#include <list>


class ShipPlayer :
	public Player
{
private:
	// input
	bool goLeft;
	bool goRight;
	bool bShoot;

	float acceleration;
	float friction;
	float maxSpeed;
	float currentSpeed = 0.f;
	const float MAX_X = 730.0f;

	float bulletSpeed;
	float cooldown; // s
	float cooldownProgress = 0.0f; // s
	void shoot();
	void setProperties() override;
public:
	void input() override;
	void update() override;
};

