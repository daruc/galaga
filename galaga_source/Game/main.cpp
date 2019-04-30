#include "Engine.h"
#include "GalagaGameScene.h"
#include "StartScene.h"
#include "GameOverScene.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	int resolutionWidth = 800;
	int resolutionHeight = 600;
	const std::string title("Galaga");
	Engine engine(title, resolutionWidth, resolutionHeight);

	GalagaGameScene * gameScene = new GalagaGameScene();
	gameScene->setName("Game");
	engine.registerScene(gameScene);

	StartScene * startScene = new StartScene();
	startScene->setName("Start");
	engine.registerScene(startScene);

	GameOverScene * gameOverScene = new GameOverScene();
	gameOverScene->setName("GameOver");
	engine.registerScene(gameOverScene);

	engine.changeScene("Start");
	engine.run();

	return 0;
}