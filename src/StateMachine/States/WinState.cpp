#include "StateMachine/States/WinState.h"

#include "StateMachine/StateMachine.h"
#include "Field/Field.h"
#include "Sprite/Sprite.h"

WinState::WinState(StateMachine* stateMachine, Field* field, Sprite* background, Sprite* foreground)
	: IState(stateMachine, field, background, foreground), m_resultController(field)
{
}

void WinState::start()
{
	m_field->finishSpin();

	m_resultController.calculatePrize();
	m_resultController.createPrizeText();
}

void WinState::clickStartButton()
{
	m_stateMachine->changeStateRun();
}

void WinState::draw(sf::RenderWindow & window) const
{
	m_background->draw(window);
	m_field->drawResultSymbols(window);
	m_foreground->draw(window);
	m_resultController.draw(window);
}
