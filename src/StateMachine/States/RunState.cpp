#include "StateMachine/States/RunState.h"

#include "StateMachine/StateMachine.h"
#include "Field/Field.h"
#include "Renderer/Renderer.h"

RunState::RunState(StateMachine * stateMachine, Field* field, Renderer* renderer)
	: IState(stateMachine, field, renderer)
{
}

void RunState::start()
{
	m_field->reset();
	m_field->startSpin();
}

void RunState::update(float dt)
{
	m_field->update(dt);
}

void RunState::clickStopButton()
{
	m_stateMachine->changeStateWin();
}

void RunState::draw(sf::RenderWindow & window) const
{
	m_renderer->drawBackground(window);
	m_field->drawAllSymbols(window);
	m_renderer->drawForeground(window);
}
