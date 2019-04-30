#pragma once
#include "Button.h"
class ExitButton :
	public Button
{
public:
	ExitButton(sf::Font * font, const std::string & str);
	void action() override;
};

