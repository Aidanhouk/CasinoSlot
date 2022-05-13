#pragma once

#include <SFML/Graphics.hpp>

class StateMachine;
class Field;
class Renderer;

class IState
{
public:
	IState(StateMachine* stateMachine, Field* field, Renderer* renderer)
		: m_stateMachine{ stateMachine }, m_field{ field }, m_renderer{ renderer }
	{};

	virtual void start() {};
	virtual void update(float dt) {};

	virtual void clickStartButton() {};
	virtual void clickStopButton() {};

	virtual void draw(sf::RenderWindow& window) const {};

protected:
	StateMachine* m_stateMachine;
	Field * m_field;

	Renderer* m_renderer;
};