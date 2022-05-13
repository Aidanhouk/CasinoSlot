#pragma once

#include "StateMachine/States/IState.h"

class Field;

class RunState : public IState
{
public:
	RunState(StateMachine* stateMachine, Field* field, Renderer* renderer);

	void start() override;
	void update(float dt) override;

	void clickStopButton() override;

	void draw(sf::RenderWindow& window) const override;
};