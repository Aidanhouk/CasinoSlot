#pragma once

#include "StateMachine/States/IState.h"

class WaitState : public IState
{
public:
	WaitState(StateMachine* stateMachine, Field* field, Renderer* renderer);

	void clickStartButton() override;

	void draw(sf::RenderWindow& window) const override;
};