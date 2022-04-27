#include "Field/Symbol/Symbol.h"

#include "Config/Config.h"
#include "Field/Symbol/SymbolTexture.h"

void Symbol::setPosition(sf::Vector2f& position)
{
	m_sprite.setPosition(position);
	m_startPosition = position;
}

void Symbol::setOffset(float y)
{
	auto newPosition = m_startPosition;
	newPosition.y += y;
	m_sprite.setPosition(newPosition);
}

void Symbol::setRandSymbol()
{
	int symbolIndex = rand() % SymbolType::NUMBER_OF_SYMBOLS;
	setSymbol(SymbolType(symbolIndex));
}

void Symbol::setSymbol(SymbolType symbolType)
{
	m_symbolType = symbolType;
	m_sprite.setTexture(SymbolTexture::getTexture(symbolType));
	m_sprite.setColor(sf::Color{ 255,255,255,255 });
}

void Symbol::makeTransparent()
{
	m_sprite.setColor(sf::Color{ 255,255,255,95 });
}

void Symbol::draw(sf::RenderWindow & window) const
{
	if (outOfRange())
		return;

	window.draw(m_sprite);
}

bool Symbol::outOfRange() const
{
	bool belowTheScreen = m_sprite.getPosition().y > g_config.resY;
	bool aboveTheScreen = m_sprite.getPosition().y + m_sprite.getTexture()->getSize().y < 0;
	return belowTheScreen || aboveTheScreen;
}
