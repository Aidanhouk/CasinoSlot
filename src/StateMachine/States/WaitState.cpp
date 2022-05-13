#include "StateMachine/States/WaitState.h"

#include "StateMachine/StateMachine.h"
#include "Field/Field.h"
#include "Renderer/Renderer.h"

WaitState::WaitState(StateMachine* stateMachine, Field* field, Renderer* renderer)
	: IState(stateMachine, field, renderer)
{
}

void WaitState::clickStartButton()
{
	m_stateMachine->changeStateRun();
}

void WaitState::draw(sf::RenderWindow & window) const
{
	m_renderer->drawBackground(window);
	m_field->drawResultSymbols(window);
	m_renderer->drawForeground(window);
}
