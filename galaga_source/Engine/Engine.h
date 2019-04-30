#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Properties.h"

class Scene;

class Engine
{
private:
	std::map<std::string, Scene *> scenes;
	Scene * currentScene = nullptr;
	Scene * newScene = nullptr;
	sf::RenderWindow window;
	bool isRunning = false;
	sf::Clock clock;
	sf::Time elapsedTime;
	int sharedData1;
	int sharedData2;
	Properties properties;
public:
	Engine(const std::string & title, int resolutionWidth, int resolutionHeight);
	void run();
	void registerScene(Scene * abstractScene);
	void changeScene(std::string sceneName, int sharedData1 = 0, int sharedData2 = 0);
	sf::RenderWindow * getWindow();
	sf::Time getElapsedTime();
	Scene * getCurrentScene();
	inline Properties* getProperties() { return &properties; }
private:
	void input(sf::Event * event);
	void update();
	void draw();
	void _changeScene();
};

