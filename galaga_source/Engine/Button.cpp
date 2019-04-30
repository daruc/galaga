#include "Button.h"

Button::Button(sf::Font * font, const std::string & str)
{
	text.setFont(*font);
	text.setString(str);
	rectangle.setFillColor(sf::Color(128, 128, 128, 255));
	rectangle.setOutlineColor(sf::Color(0, 0, 40, 255));
	rectangle.setOutlineThickness(4.f);
	sf::Vector2f rectSize(text.getLocalBounds().width + 10, text.getLocalBounds().height * 2);
	rectangle.setSize(rectSize);

	leftReleased = true;
	rightReleased = true;
	upReleased = true;
	downReleased = true;
}

void Button::input(sf::Event * event)
{
	if (focus)
	{
		if (!pressed)
		{
			pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
		}
		if (leftButton != NULL && !leftPressed && leftReleased)
		{
			leftPressed = event->type == sf::Event::KeyPressed &&
				event->key.code == sf::Keyboard::Left;
		}
		if (rightButton != NULL && !rightPressed && rightReleased)
		{
			rightPressed = event->type == sf::Event::KeyPressed &&
				event->key.code == sf::Keyboard::Right;
		}
		if (topButton != NULL && !upPressed && upReleased)
		{
			upPressed = event->type == sf::Event::KeyPressed &&
				event->key.code == sf::Keyboard::Up;
		}
		if (bottomButton != NULL && !downPressed && downReleased)
		{
			downPressed = event->type == sf::Event::KeyPressed &&
				event->key.code == sf::Keyboard::Down;
		}

		if (!leftReleased)
		{
			leftReleased = event->type == sf::Event::KeyReleased &&
				event->key.code == sf::Keyboard::Left;
		}
		if (!rightReleased)
		{
			rightReleased = event->type == sf::Event::KeyReleased &&
				event->key.code == sf::Keyboard::Right;
		}
		if (!upReleased)
		{
			upReleased = event->type == sf::Event::KeyReleased &&
				event->key.code == sf::Keyboard::Up;
		}
		if (!downReleased)
		{
			downReleased = event->type == sf::Event::KeyReleased &&
				event->key.code == sf::Keyboard::Down;
		}
	}
}

void Button::update()
{
	if (pressed)
	{
		pressed = false;
		action();
	}
	if (leftPressed)
	{
		leftPressed = false;
		setFocus(false);
		leftButton->setFocus(true);
		leftButton->leftReleased = false;
	}
	else if (rightPressed)
	{
		rightPressed = false;
		setFocus(false);
		rightButton->setFocus(true);
		rightButton->rightReleased = false;
	}
	else if (upPressed)
	{
		upPressed = false;
		setFocus(false);
		topButton->setFocus(true);
		topButton->upReleased = false;
	}
	else if (downPressed)
	{
		downPressed = false;
		setFocus(false);
		bottomButton->setFocus(true);
		bottomButton->downReleased = false;
	}
}

void Button::draw()
{
	engine->getWindow()->draw(rectangle);
	engine->getWindow()->draw(text);
}

void Button::setPosition(float x, float y)
{
	rectangle.setPosition(x, y);
	text.setPosition(x + 5.f, y + 5.f);
}

void Button::setFocus(bool focus)
{
	this->focus = focus;
	if (focus)
	{
		rectangle.setOutlineColor(sf::Color::Cyan);
	}
	else
	{
		rectangle.setOutlineColor(sf::Color(50, 50, 100, 255));
	}
}
