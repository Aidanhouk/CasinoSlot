#pragma once

#include "StateMachine/States/IState.h"

class WaitState : public IState
{
public:
	WaitState(StateMachine* stateMachine, Field* field);

	virtual void clickStartButton() override;

	virtual void draw(sf::RenderWindow& window) const override;
};