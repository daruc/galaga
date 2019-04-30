#pragma once
#include "Scene.h"
#include <list>
#include "Enemy.h"
#include "InteractiveBackground.h"
#include "Bullet.h"
#include "Player.h"
#include "HudElement.h"

class GameScene : public Scene
{
private:
	void releaseRemovedInteractiveObjects();
protected:
	Player * player;
	std::list<Enemy *> enemies;
	std::list<Bullet *> bullets;
	std::list<HudElement* > hudElements;
	InteractiveBackground * interactiveBackground;
public:
	void registerScene(Engine * engine) override;
	void release() override;
	void input(sf::Event * event) override;
	void update() override;
	void draw() override;
	void addBullet(Bullet * bullet);
	inline std::list<Enemy *>* getEnemies() { return &enemies; }
	inline Player * getPlayer() { return player; }
};

