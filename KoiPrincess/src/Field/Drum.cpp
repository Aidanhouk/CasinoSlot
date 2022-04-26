#include "Field/Drum.h"

#include "Config/Config.h"
#include "Field/Field.h"

Drum::Drum()
{
	for (auto & symbol : m_symbols)
	{
		symbol.setRandSymbol();
	}

	m_symbolHeight = g_config.resY * 0.25f;
}

void Drum::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	putResultSymbolsOnScreen();
}

void Drum::putResultSymbolsOnScreen()
{
	// this function is called when STOP button is pressed to put result symbols on screen
	for (size_t i = N_SYMBOLS_PER_SPIN - N_ROWS_ON_SCREEN; i < N_SYMBOLS_PER_SPIN; i++)
	{
		auto startPos = m_position;
		startPos.y -= (i + N_ROWS_ON_SCREEN - N_SYMBOLS_PER_SPIN) * m_symbolHeight;
		m_symbols[i].setPosition(startPos);
	}
}

void Drum::move(float dt)
{
	if (m_spinController.checkForSpinEnd())
	{
		m_field->drumStopSpin();
		return;
	}

	float offset = m_spinController.updateOffset();

	for (auto & symbol : m_symbols)
	{
		symbol.setOffset(offset);
	}
}

void Drum::reset()
{
	// last (result) symbols of the previous spin become first symbols of the next
	for (size_t i = 0; i < N_ROWS_ON_SCREEN; i++)
	{
		m_symbols[i].setSymbol(m_symbols[N_SYMBOLS_PER_SPIN - N_ROWS_ON_SCREEN + i].getSymbolType());
	}

	// randomize rest of the symbols
	for (size_t i = N_ROWS_ON_SCREEN; i < N_SYMBOLS_PER_SPIN; i++)
	{
		m_symbols[i].setRandSymbol();
	}

	resetSymbolsPositions();
}

void Drum::startSpin()
{
	m_spinController.resetSpinTimer();
}

void Drum::finishSpin()
{
	putResultSymbolsOnScreen();
}

void Drum::getResultSymbols(Symbol** result)
{
	// this function returns pointers to the result symbols
	// that will be used to calculate prize
	for (size_t i = 0; i < N_ROWS_ON_SCREEN; i++)
	{
		*result = &(m_symbols[N_SYMBOLS_PER_SPIN - 1 - i]);
		result++;
	}
}

void Drum::resetSymbolsPositions()
{
	for (size_t i = 0; i < N_SYMBOLS_PER_SPIN; i++)
	{
		auto startPos = m_position;
		startPos.y -= i * m_symbolHeight;
		m_symbols[i].setPosition(startPos);
	}
}

void Drum::drawAllSymbols(sf::RenderWindow & window) const
{
	for (auto & symbol : m_symbols)
	{
		symbol.draw(window);
	}
}

void Drum::drawResultSymbols(sf::RenderWindow & window) const
{
	for (size_t i = N_SYMBOLS_PER_SPIN - N_ROWS_ON_SCREEN; i < N_SYMBOLS_PER_SPIN; i++)
	{
		m_symbols[i].draw(window);
	}
}
