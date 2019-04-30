#include "Engine.h"

Engine::Engine(const std::string & title, int resolutionWidth, int resolutionHeight)
	: window(sf::VideoMode(resolutionWidth, resolutionHeight), title), properties("params.properties")
{
	window.setKeyRepeatEnabled(false);
	srand(time(0));
}


void Engine::run()
{
	isRunning = true;
	clock.restart();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		currentScene->input(&event);
		currentScene->update();
		window.clear();
		currentScene->draw();
		window.display();
		_changeScene();
		elapsedTime = clock.restart();
	}
	isRunning = false;
}

void Engine::registerScene(Scene * abstractScene)
{
	scenes[abstractScene->getName()] = abstractScene;
}

void Engine::changeScene(std::string sceneName, int sharedData1, int sharedData2)
{
	this->sharedData1 = sharedData1;
	this->sharedData2 = sharedData2;
	if (isRunning)
	{
		newScene = scenes[sceneName];
		elapsedTime = sf::Time();
	}
	else
	{
		currentScene = scenes[sceneName];
		currentScene->load(sharedData1, sharedData2);
		currentScene->registerScene(this);
	}
}

void Engine::_changeScene()
{
	if (newScene)
	{
		currentScene->release();
		currentScene->_release();
		currentScene = newScene;
		currentScene->load(sharedData1, sharedData2);
		currentScene->registerScene(this);
		newScene = nullptr;
	}
}

sf::RenderWindow * Engine::getWindow()
{
	return &window;
}

sf::Time Engine::getElapsedTime()
{
	return elapsedTime;
}

Scene * Engine::getCurrentScene()
{
	return currentScene;
}

void Engine::input(sf::Event * event)
{
	currentScene->input(event);
}

void Engine::update()
{
	currentScene->update();
}

void Engine::draw()
{
	currentScene->draw();
}
