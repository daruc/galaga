#pragma once
#include "HudElement.h"
class Button :
	public HudElement
{
protected:
	bool focus;

	bool pressed;
	bool leftPressed;
	bool rightPressed;
	bool upPressed;
	bool downPressed;

	bool leftReleased;
	bool rightReleased;
	bool upReleased;
	bool downReleased;

	sf::RectangleShape rectangle;
	sf::Text text;

	Button * leftButton;
	Button * rightButton;
	Button * topButton;
	Button * bottomButton;
public:
	Button(sf::Font * font, const std::string & str);
	void input(sf::Event * event) override;
	void update() override;
	void draw() override;
	virtual void action() = 0;
	void setPosition(float x, float y);
	void setFocus(bool focus);

	inline void setLeftButton(Button * button) { leftButton = button; }
	inline void setRightButton(Button * button) { rightButton = button; }
	inline void setTopButton(Button * button) { topButton = button; }
	inline void setBottomButton(Button * button) { bottomButton = button; }
};

