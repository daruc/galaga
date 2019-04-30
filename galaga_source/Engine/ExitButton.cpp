#include "ExitButton.h"

ExitButton::ExitButton(sf::Font * font, const std::string & str)
	: Button(font, str)
{
}

void ExitButton::action()
{
	engine->getWindow()->close();
}