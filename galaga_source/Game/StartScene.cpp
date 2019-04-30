#include "StartScene.h"


void StartScene::load(int sharedData1, int sharedData2)
{
	loadFontFromFile("Assets/Fonts/androidnation.ttf");

	titleLabel = new Label(font);
	titleLabel->setColor(sf::Color::White);
	titleLabel->setText("Galaga");
	titleLabel->setPosition(220.f, 130.f);
	titleLabel->setSize(70U);
	hudElements.push_back(titleLabel);

	startGameButton = new StartGameButton(font, "Start");
	startGameButton->setFocus(true);
	startGameButton->setPosition(340.f, 350.f);
	hudElements.push_back(startGameButton);

	howToPlayLabel = new Label(font);
	howToPlayLabel->setColor(sf::Color::White);
	howToPlayLabel->setText("Control: |Left|, |Right|, |Space| = Shoot, |Enter| = Press the button");
	howToPlayLabel->setPosition(15.f, 570.f);
	howToPlayLabel->setSize(15U);
	hudElements.push_back(howToPlayLabel);
}
