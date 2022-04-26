#include "Field/Field.h"

#include "Config/Config.h"
#include "StateMachine/StateMachine.h"

Field::Field(StateMachine * stateMachine)
	: m_stateMachine(stateMachine)
{
	// set drums positions and spinning times
	const float xShift = g_config.resX * 0.01f;
	const float distanceBetweenDrums = g_config.resX * 0.14f;

	const float startY = g_config.resY * 0.6f;
	for (size_t i = 0; i < N_DRUMS; i++)
	{
		float startX = xShift + (i + 1) * distanceBetweenDrums;
		m_drums[i].setPosition(startX, startY);
		// most right drum has spinning time = SPIN_TIME,
		// each one to the left has spinning time less by TIME_BETWEEN_DRUM_SPINS
		m_drums[i].setSpinTime(SPIN_TIME - (N_DRUMS - 1 - i) * TIME_BETWEEN_DRUM_SPINS);
		
		m_drums[i].setField(this);
	}
}

void Field::update(float dt)
{
	for (size_t i = m_nextDrumToStop; i < N_DRUMS; i++)
	{
		m_drums[i].move(dt);
	}
}

void Field::reset()
{
	for (auto & drum : m_drums)
	{
		drum.reset();
	}
}

void Field::startSpin()
{
	for (auto & drum : m_drums)
	{
		drum.startSpin();
	}
}

void Field::finishSpin()
{
	m_nextDrumToStop = 0u;

	for (auto & drum : m_drums)
	{
		drum.finishSpin();
	}
}

void Field::drumStopSpin()
{
	m_nextDrumToStop++;

	if (m_nextDrumToStop == N_DRUMS)
	{
		m_stateMachine->changeStateWin();
	}
}

void Field::getResultSymbols(std::array<Symbol*, N_ROWS_ON_SCREEN*N_DRUMS>& resultSymbols)
{
	// this function returns pointers to the result symbols
	// that will be used to calculate prize
	Symbol** resSymbols = resultSymbols.data();
	for (auto & drum : m_drums)
	{
		drum.getResultSymbols(resSymbols);
		resSymbols += N_ROWS_ON_SCREEN;
	}
}

void Field::drawAllSymbols(sf::RenderWindow & window) const
{
	for (auto & drum : m_drums)
	{
		drum.drawAllSymbols(window);
	}
}

void Field::drawResultSymbols(sf::RenderWindow & window) const
{
	for (auto & drum : m_drums)
	{
		drum.drawResultSymbols(window);
	}
}
