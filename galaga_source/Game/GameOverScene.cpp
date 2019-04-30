#include "GameOverScene.h"

void GameOverScene::load(int sharedData1, int sharedData2)
{
	loadFontFromFile("Assets/Fonts/androidnation.ttf");

	gameOverLabel = new Label(font);
	gameOverLabel->setColor(sf::Color::Red);
	gameOverLabel->setText("Game Over");
	gameOverLabel->setPosition(160.f, 130.f);
	gameOverLabel->setSize(60);
	hudElements.push_back(gameOverLabel);

	scoreLabel = new Label(font);
	scoreLabel->setColor(sf::Color::White);
	scoreLabel->setText("Score: " + std::to_string(sharedData1));
	scoreLabel->setPosition(270.f, 300.f);
	hudElements.push_back(scoreLabel);

	levelLabel = new Label(font);
	levelLabel->setColor(sf::Color::White);
	levelLabel->setText("Level: " + std::to_string(sharedData2));
	levelLabel->setPosition(270.f, 380.f);
	hudElements.push_back(levelLabel);

	restartButton = new StartGameButton(font, "Restart");
	restartButton->setFocus(true);
	restartButton->setPosition(220.f, 500.f);
	hudElements.push_back(restartButton);

	exitButton = new ExitButton(font, "Exit");
	exitButton->setPosition(470.f, 500.f);
	hudElements.push_back(exitButton);

	restartButton->setRightButton(exitButton);
	exitButton->setLeftButton(restartButton);
}
