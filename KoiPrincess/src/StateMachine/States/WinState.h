#pragma once

#include "StateMachine/States/IState.h"

#include "ResultController/ResultController.h"

class WinState : public IState
{
public:
	WinState(StateMachine* stateMachine, Field* field);

	virtual void start() override;

	virtual void clickStartButton() override;

	virtual void draw(sf::RenderWindow& window) const override;
private:
	ResultController m_resultController;
};