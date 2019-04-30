#pragma once
#include "Button.h"

class StartGameButton :
	public Button
{
public:
	StartGameButton(sf::Font * font, const std::string & str);
	void action() override;
};

