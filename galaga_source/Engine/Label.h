#pragma once
#include "HudElement.h"
#include <SFML/Graphics.hpp>

class Label :
	public HudElement
{
private:
	sf::Text text;
public:
	Label(sf::Font * font);
	void setText(const std::string & str);
	void setColor(const sf::Color & color);
	void setSize(unsigned int size = 30);
	void setPosition(float x, float y);
	void input(sf::Event * event) override;
	void update() override;
	void draw() override;
};

