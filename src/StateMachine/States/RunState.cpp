#include "StateMachine/States/RunState.h"

#include "StateMachine/StateMachine.h"
#include "Field/Field.h"

#include "Sprite/Sprite.h"

RunState::RunState(StateMachine * stateMachine, Field* field, Sprite* background, Sprite* foreground)
	: IState(stateMachine, field, background, foreground)
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
	m_background->draw(window);
	m_field->drawAllSymbols(window);
	m_foreground->draw(window);
}
