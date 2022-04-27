#pragma once

#include "StateMachine/States/IState.h"

class Field;

class RunState : public IState
{
public:
	RunState(StateMachine* stateMachine, Field* field);

	virtual void start() override;
	virtual void update(float dt) override;

	virtual void clickStopButton() override;

	virtual void draw(sf::RenderWindow& window) const override;
};