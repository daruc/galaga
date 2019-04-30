#pragma once
#include "GameScene.h"

class MenuScene : public Scene
{
protected:
	std::list<HudElement* > hudElements;
public:
	void registerScene(Engine * engine) override;
	void input(sf::Event * event) override;
	void update() override;
	void draw() override;
	void release() override;
};

