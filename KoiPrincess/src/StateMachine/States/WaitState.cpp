#include "StateMachine/States/WaitState.h"

#include "StateMachine/StateMachine.h"
#include "Field/Field.h"

WaitState::WaitState(StateMachine* stateMachine, Field* field)
	: IState(stateMachine, field)
{
}

void WaitState::clickStartButton()
{
	m_stateMachine->changeStateRun();
}

void WaitState::draw(sf::RenderWindow & window) const
{
	m_background.draw(window);
	m_field->drawResultSymbols(window);
	m_foreground.draw(window);
}
