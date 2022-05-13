#pragma once

#include "Constants.h"
#include "Field/Drum.h"

#include <array>
#include <SFML/Graphics.hpp>

class StateMachine;

class Field
{
public:
	Field(StateMachine * stateMachine);

	void update(float dt);
	void reset();
	void startSpin();
	void finishSpin();
	void drumStopSpin();

	void setResultSymbols(std::array<Symbol*, N_ROWS_ON_SCREEN * N_DRUMS> & resultSymbols);

	void drawAllSymbols(sf::RenderWindow& window) const;
	void drawResultSymbols(sf::RenderWindow& window) const;

private:
	std::array<Drum, N_DRUMS> m_drums;

	unsigned int m_nextDrumToStop = 0u;

	StateMachine* m_stateMachine;
};