#pragma once

#include "Constants.h"
#include "Sprite/Sprite.h"

#include <array>

class Symbol;
class Field;

class ResultController
{
public:
	ResultController(Field * field);

	void calculatePrize();
	void createPrizeText();

	void draw(sf::RenderWindow& window) const;
private:
	void setTextSettings();

	std::array<Symbol*, N_ROWS_ON_SCREEN * N_DRUMS> m_resultSymbols;

	int m_prize;

	Sprite m_prizeWindow;

	sf::Font m_font;
	sf::Text m_prizeText;
};