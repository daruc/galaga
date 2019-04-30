#include "MenuScene.h"

void MenuScene::registerScene(Engine * engine)
{
	Scene::registerScene(engine);
	for (HudElement * hudElement : hudElements)
	{
		hudElement->setEngine(engine);
	}
}

void MenuScene::input(sf::Event * event)
{
	for (HudElement * hudElement : hudElements)
	{
		hudElement->input(event);
	}
}

void MenuScene::update()
{
	for (HudElement * hudElement : hudElements)
	{
		hudElement->update();
	}
}

void MenuScene::draw()
{
	for (HudElement * hudElement : hudElements)
	{
		hudElement->draw();
	}
}

void MenuScene::release()
{
	while (!hudElements.empty())
	{
		HudElement * hudElement = hudElements.back();
		delete hudElement;
		hudElements.pop_back();
	}
}
