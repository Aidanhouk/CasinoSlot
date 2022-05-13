#include "StateMachine/States/WinState.h"

#include "StateMachine/StateMachine.h"
#include "Field/Field.h"
#include "Renderer/Renderer.h"

WinState::WinState(StateMachine* stateMachine, Field* field, Renderer* renderer)
	: IState(stateMachine, field, renderer), m_resultController(field)
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
	m_renderer->drawBackground(window);
	m_field->drawResultSymbols(window);
	m_renderer->drawForeground(window);
	m_resultController.draw(window);
}
