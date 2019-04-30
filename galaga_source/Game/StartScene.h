#pragma once
#include "MenuScene.h"
#include "Label.h"
#include "StartGameButton.h"

class StartScene :
	public MenuScene
{
private:
	Label * titleLabel;
	Label * howToPlayLabel;
	StartGameButton * startGameButton;
public:
	void load(int sharedData1, int sharedData2) override;
};

