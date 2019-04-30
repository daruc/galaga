#include "Scene.h"

void Scene::registerScene(Engine * engine)
{
	this->engine = engine;
	setProperties();
}

void Scene::setName(std::string name)
{
	this->name = name;
}

void Scene::loadFontFromFile(const std::string & filename)
{
	font = new sf::Font();
	font->loadFromFile(filename);
}

std::string Scene::getName() const
{
	return name;
}

sf::Texture* Scene::getTexture(std::string filename)
{
	if (textures.find(filename) == textures.end())
	{
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(filename);
		textures[filename] = texture;
	}

	return textures[filename];
}

void Scene::_release()
{
	for (auto textureKeyValue : textures)
	{
		delete textureKeyValue.second;
	}
	textures.clear();
	if (font)
	{
		delete font;
		font = nullptr;
	}
}
