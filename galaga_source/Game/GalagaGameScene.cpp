#include "GalagaGameScene.h"
#include "TripleBackground.h"
#include "ShipPlayer.h"
#include "UnarmedEnemy.h"
#include "ArmedEnemy.h"
#include "Label.h"

void GalagaGameScene::load(int sharedData1, int sharedData2)
{
	level = 1;
	score = 0;
	isReplayLevel = false;

	srand(time(NULL));
	initHud();
	setBackground();
	spawnPlayer();
}

void GalagaGameScene::update()
{
	GameScene::update();
	if (enemiesLeft == 0)
	{
		spawnEnemies(true);
	}
	if (isReplayLevel)
	{
		isReplayLevel = false;
		--lives;
		refreshLabels();
		if (lives < 0)
		{
			engine->changeScene("GameOver", score, level);
		}

		for (Enemy* enemy : enemies)
		{
			enemy->remove();
		}
		for (Bullet* bullet : bullets)
		{
			bullet->remove();
		}
		spawnEnemies(false);
	}
}

void GalagaGameScene::decrementEnemiesLeft(int baseScore)
{
	if (enemiesLeft > 0)
	{
		--enemiesLeft;
		score += baseScore + (baseScore / 2) * (level - 1);
		refreshLabels();
	}
}

void GalagaGameScene::replayLevel()
{
	isReplayLevel = true;
}

void GalagaGameScene::initHud()
{
	loadFontFromFile("Assets/Fonts/androidnation.ttf");

	levelLabel = new Label(font);

	levelLabel->setColor(sf::Color::White);
	levelLabel->setPosition(320.f, 0.f);
	levelLabel->setSize(27);
	hudElements.push_back(levelLabel);

	livesLabel = new Label(font);
	livesLabel->setColor(sf::Color::White);
	livesLabel->setPosition(585.f, 0.f);
	livesLabel->setSize(27);
	hudElements.push_back(livesLabel);

	scoreLabel = new Label(font);
	scoreLabel->setColor(sf::Color::White);
	scoreLabel->setSize(27);
	hudElements.push_back(scoreLabel);

	refreshLabels();
}

void GalagaGameScene::refreshLabels()
{
	levelLabel->setText("Level " + std::to_string(level));
	livesLabel->setText("Lives " + std::to_string(lives));
	scoreLabel->setText("Score " + std::to_string(score));
}

void GalagaGameScene::setBackground()
{
	TripleBackground * tripleBackground = new TripleBackground(SCROLL_DOWN, 40.0f, 20.0f, 10.0f);
	tripleBackground->setTexture(1, getTexture("Assets/Graphics/GameBackground1.png"));
	tripleBackground->setTexture(2, getTexture("Assets/Graphics/GameBackground2.png"));
	tripleBackground->setTexture(3, getTexture("Assets/Graphics/GameBackground3.png"));
	interactiveBackground = tripleBackground;
}

void GalagaGameScene::spawnEnemies(bool isNewLevel)
{
	if (isNewLevel)
	{
		numberEnemies += extraEnemies;
		if (numberEnemies > 24)
		{
			numberEnemies = 24;
		}
		horizontalSpeed += extraHorizontalSpeed;
		verticalSpeed += extraVerticalSpeed;

		++level;
		refreshLabels();
	}
	enemiesLeft = numberEnemies;


	float offsetX = 0.f;
	if (numberEnemies < 6)
	{
		offsetX += (6 - numberEnemies) * 50.f;
	}
	for (int i = 0; i < numberEnemies; ++i)
	{
		float x = offsetX + 100.f * (i % 6);
		float y = 50.f + 100.f * (i / 6);
		spawnRandomEnemy(x, y);
	}
}

void GalagaGameScene::spawnRandomEnemy(float x, float y)
{

	if (std::rand() % 2)
	{
		UnarmedEnemy * unarmedEnemy = new UnarmedEnemy();
		unarmedEnemy->setPosition(x, y);
		unarmedEnemy->setTexture(getTexture("Assets/Graphics/UnarmedEnemy.png"));
		if (engine)
		{
			unarmedEnemy->setEngine(engine);
			unarmedEnemy->setSpeed(horizontalSpeed, verticalSpeed);
		}
		enemies.push_back(unarmedEnemy);
	}
	else
	{
		ArmedEnemy * armedEnemy = new ArmedEnemy();
		armedEnemy->setPosition(x, y);
		armedEnemy->setTexture(getTexture("Assets/Graphics/ArmedEnemy.png"));
		if (engine)
		{
			armedEnemy->setEngine(engine);
			armedEnemy->setSpeed(horizontalSpeed, verticalSpeed);
		}
		enemies.push_back(armedEnemy);
	}
}

void GalagaGameScene::spawnPlayer()
{
	player = new ShipPlayer();
	player->setPosition(370.0f, 520.f);
	player->setTexture(getTexture("Assets/Graphics/Player.png"));
}

void GalagaGameScene::setProperties()
{
	Properties * prop = engine->getProperties();

	lives = prop->get<float>("player.lives");
	numberEnemies = prop->get<float>("level.enemies");
	enemiesLeft = numberEnemies;
	spawnEnemies(false);

	refreshLabels();

	horizontalSpeed = prop->get<float>("level.horizontalSpeed");
	verticalSpeed = prop->get<float>("level.verticalSpeed");
	for (Enemy * enemy : enemies)
	{
		EnemyWithSpeed* enemyWithSpeed = dynamic_cast<EnemyWithSpeed*>(enemy);
		enemyWithSpeed->setSpeed(horizontalSpeed, verticalSpeed);
	}

	extraHorizontalSpeed = prop->get<float>("level.new.extraHorizontalSpeed");
	extraVerticalSpeed = prop->get<float>("level.new.extraVerticalSpeed");
	extraEnemies = prop->get<float>("level.new.extraEnemies");
}
