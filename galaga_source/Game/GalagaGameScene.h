#pragma once
#include <GameScene.h>
#include "Label.h"

class GalagaGameScene :
	public GameScene
{
private:
	int numberEnemies;
	int enemiesLeft;
	float horizontalSpeed;
	float verticalSpeed;
	bool isReplayLevel;

	int level;
	int lives;
	int score;

	float extraHorizontalSpeed;
	float extraVerticalSpeed;
	float extraEnemies;

	Label * levelLabel = nullptr;
	Label * livesLabel = nullptr;
	Label * scoreLabel = nullptr;
public:
	void load(int sharedData1, int sharedData2) override;
	void update() override;
	void decrementEnemiesLeft(int baseScore);
	void replayLevel();
private:
	void initHud();
	void refreshLabels();
	void setBackground();
	void spawnEnemies(bool isNewLevel);
	void spawnRandomEnemy(float x, float y);
	void spawnPlayer();
	void setProperties() override;
};

