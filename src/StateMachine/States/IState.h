#pragma once

#include <SFML/Graphics.hpp>

class StateMachine;
class Field;
class Sprite;

class IState
{
public:
	IState(StateMachine* stateMachine, Field* field, Sprite* background, Sprite* foreground)
		: m_stateMachine{ stateMachine }, m_field{ field }, m_background{ background }, m_foreground{ foreground }
	{};

	virtual void start() {};
	virtual void update(float dt) {};

	virtual void clickStartButton() {};
	virtual void clickStopButton() {};

	virtual void draw(sf::RenderWindow& window) const {};

protected:
	StateMachine* m_stateMachine;
	Field * m_field;

	Sprite* m_background;
	Sprite* m_foreground;
};