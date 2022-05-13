#include "Field/Drum.h"

#include "Field/Field.h"

Drum::Drum()
	: m_field(nullptr)
{
	for (auto & symbol : m_symbols)
	{
		symbol.setRandSymbol();
	}
}

void Drum::setPosition(float x, float y)
{
	m_position.x = x;
	m_position.y = y;

	putResultSymbolsOnScreen();
}

// this function is called when STOP button is pressed to put result symbols on screen
void Drum::putResultSymbolsOnScreen()
{
	for (size_t i = 0; i < N_ROWS_ON_SCREEN; i++)
	{
		auto startPos = m_position;
		startPos.y -= i * SYMBOL_HEIGHT_PIXELS;
		m_symbols[FIRST_RESULT_SYMBOL_INDEX + i].setPosition(startPos);
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
		m_symbols[i].setSymbol(m_symbols[FIRST_RESULT_SYMBOL_INDEX + i].getSymbolType());
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

// this function sets pointers to the result symbols
// that will be used to calculate prize
void Drum::setResultSymbols(Symbol** result)
{
	for (size_t i = 0; i < N_ROWS_ON_SCREEN; i++)
	{
		// set pointer to result symbol
		*result = &(m_symbols[FIRST_RESULT_SYMBOL_INDEX + i]);
		result++;
	}
}

void Drum::resetSymbolsPositions()
{
	for (size_t i = 0; i < N_SYMBOLS_PER_SPIN; i++)
	{
		auto startPos = m_position;
		startPos.y -= i * SYMBOL_HEIGHT_PIXELS;
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
	for (size_t i = FIRST_RESULT_SYMBOL_INDEX; i < N_SYMBOLS_PER_SPIN; i++)
	{
		m_symbols[i].draw(window);
	}
}
