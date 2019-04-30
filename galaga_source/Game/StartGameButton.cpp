#include "StartGameButton.h"



StartGameButton::StartGameButton(sf::Font * font, const std::string & str)
	: Button(font, str)
{

}

void StartGameButton::action()
{
	engine->changeScene("Game");
}
