#pragma once
#include <MenuScene.h>
#include "Label.h"
#include "StartGameButton.h"
#include "ExitButton.h"

class GameOverScene :
	public MenuScene
{
private:
	Label * gameOverLabel = NULL;
	Label * scoreLabel;
	Label * levelLabel;
	StartGameButton * restartButton = NULL;
	ExitButton * exitButton = NULL;
public:
	void load(int sharedData1, int sharedData2) override;
};

