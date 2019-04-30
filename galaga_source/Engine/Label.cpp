#include "Label.h"



Label::Label(sf::Font * font)
{
	text.setFont(*font);
}

void Label::setText(const std::string & str)
{
	text.setString(str);
}

void Label::setColor(const sf::Color & color)
{
	text.setFillColor(color);
}

void Label::setSize(unsigned int size)
{
	text.setCharacterSize(size);
}

void Label::setPosition(float x, float y)
{
	text.setPosition(x, y);
}

void Label::input(sf::Event * event)
{
}

void Label::update()
{
}

void Label::draw()
{
	engine->getWindow()->draw(text);
}

