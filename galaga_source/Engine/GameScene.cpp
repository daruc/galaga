#include "GameScene.h"

void GameScene::input(sf::Event * event)
{
	player->input();
}

void GameScene::update()
{
	player->update();
	for (Enemy * enemy : enemies)
	{
		enemy->update();
	}
	for (Bullet * bullet : bullets)
	{
		bullet->update();
	}
	interactiveBackground->update();

	releaseRemovedInteractiveObjects();
}

void GameScene::draw()
{
	interactiveBackground->draw();
	player->draw();
	for (Enemy * enemy : enemies)
	{
		enemy->draw();
	}
	for (Bullet * bullet : bullets)
	{
		bullet->draw();
	}

	for (HudElement * hudElement : hudElements)
	{
		hudElement->draw();
	}
}

bool bulletIsReadyToRemove(Bullet* bullet)
{
	return bullet->isReadyToRemove();
}

bool enemyIsReadyToRemove(Enemy* enemy)
{
	return enemy->isReadyToRemove();
}

void GameScene::releaseRemovedInteractiveObjects()
{
	bullets.remove_if(bulletIsReadyToRemove);
	enemies.remove_if(enemyIsReadyToRemove);
}


void GameScene::registerScene(Engine * engine)
{
	Scene::registerScene(engine);
	player->setEngine(engine);
	for (Enemy * enemy : enemies)
	{
		enemy->setEngine(engine);
	}
	for (Bullet * bullet : bullets)
	{
		bullet->setEngine(engine);
	}
	interactiveBackground->setEngine(engine);
	for (HudElement * hudElement : hudElements)
	{
		hudElement->setEngine(engine);
	}
}

void GameScene::release()
{
	if (player)
	{
		delete player;
		player = nullptr;
	}
	while (!enemies.empty())
	{
		Enemy * enemy = enemies.back();
		delete enemy;
		enemies.pop_back();
	}
	while (!bullets.empty())
	{
		Bullet * bullet = bullets.back();
		delete bullet;
		bullets.pop_back();
	}
	while (!hudElements.empty())
	{
		HudElement * hudElement = hudElements.back();
		delete hudElement;
		hudElements.pop_back();
	}
	delete interactiveBackground;
	interactiveBackground = nullptr;
	engine = nullptr;
}

void GameScene::addBullet(Bullet * bullet)
{
	bullet->setEngine(engine);
	bullets.push_back(bullet);
}