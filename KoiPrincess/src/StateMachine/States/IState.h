#pragma once

#include "Sprite/Sprite.h"

#include <SFML/Graphics.hpp>

class StateMachine;
class Field;

class IState
{
public:
	IState(StateMachine* stateMachine, Field* field);

	virtual void start() {};
	virtual void update(float dt) {};

	virtual void clickStartButton() {};
	virtual void clickStopButton() {};

	virtual void draw(sf::RenderWindow& window) const {};

protected:
	StateMachine* m_stateMachine;
	Field * m_field;

	Sprite m_background;
	Sprite m_foreground;
};