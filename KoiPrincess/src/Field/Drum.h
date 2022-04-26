#pragma once

#include "Constants.h"
#include "Symbol/Symbol.h"
#include "SpinController/SpinController.h"

#include <array>
#include <SFML/Graphics.hpp>

class Field;

class Drum
{
public:
	Drum();
	void setPosition(float x, float y);
	void setField(Field* field) { m_field = field; }
	void putResultSymbolsOnScreen();

	void move(float dt);
	void reset();
	void startSpin();
	void finishSpin();

	void getResultSymbols(Symbol** result);

	void drawAllSymbols(sf::RenderWindow& window) const;
	void drawResultSymbols(sf::RenderWindow& window) const;

	void setSpinTime(float spinTime) { m_spinController.setSpinTime(spinTime); }
private:
	void resetSymbolsPositions();

	std::array<Symbol, N_SYMBOLS_PER_SPIN> m_symbols;
	float m_symbolHeight;

	sf::Vector2f m_position;

	SpinController m_spinController;

	Field* m_field;
};