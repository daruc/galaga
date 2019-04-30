#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "Engine.h"

class Engine;

class Scene
{
private:
	std::string name;
protected:
	Engine * engine;
	std::map<std::string, sf::Texture*> textures;
	sf::Font * font;
	virtual void setProperties() {}
public:
	virtual void registerScene(Engine * engine);
	virtual void load(int sharedData1, int sharedData2) = 0;
	virtual void release() = 0;
	virtual void input(sf::Event * event) = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	void setName(std::string name);
	void loadFontFromFile(const std::string & filename);
	inline sf::Font * getFont() { return font; }
	std::string getName() const;

	sf::Texture* getTexture(std::string filename);
	void _release();
};

