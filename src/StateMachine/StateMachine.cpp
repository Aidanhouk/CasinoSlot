#include "StateMachine/StateMachine.h"

StateMachine::StateMachine(Field * field, Sprite* background, Sprite* foreground)
	: m_waitState(this, field, background, foreground),
	m_runState(this, field, background, foreground),
	m_winState(this, field, background, foreground)
{
	m_currentState = &m_waitState;
}

void StateMachine::update(float dt)
{
	m_currentState->update(dt);
}

void StateMachine::clickStartButton()
{
	m_currentState->clickStartButton();
}

void StateMachine::clickStopButton()
{
	m_currentState->clickStopButton();
}

void StateMachine::draw(sf::RenderWindow & window) const
{
	m_currentState->draw(window);
}

void StateMachine::changeStateWait()
{
	m_currentState = &m_waitState;
	m_currentState->start();
}

void StateMachine::changeStateRun()
{
	m_currentState = &m_runState;
	m_currentState->start();
}

void StateMachine::changeStateWin()
{
	m_currentState = &m_winState;
	m_currentState->start();
}
