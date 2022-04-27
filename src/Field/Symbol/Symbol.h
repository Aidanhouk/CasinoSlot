#pragma once

#include "Field/Symbol/SymbolType.h"

#include <SFML/Graphics.hpp>

class Symbol
{
public:
	void setPosition(sf::Vector2f& position);
	void setOffset(float y);

	void setRandSymbol();
	void setSymbol(SymbolType symbolType);

	void makeTransparent();

	void draw(sf::RenderWindow & window) const;

	SymbolType getSymbolType() { return m_symbolType; }
private:
	bool outOfRange() const;

	sf::Vector2f m_startPosition;
	SymbolType m_symbolType;
	sf::Sprite m_sprite;
};