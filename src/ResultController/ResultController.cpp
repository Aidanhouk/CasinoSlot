#include "ResultController/ResultController.h"

#include "Field/Field.h"

#include <iostream>

ResultController::ResultController(Field * field)
{
	field->setResultSymbols(m_resultSymbols);

	m_prizeWindow.loadFromFile("prize_window");
	m_prizeWindow.setPosition({ 640, 570 });

	setTextSettings();
}

void ResultController::setTextSettings()
{
	m_font.loadFromFile("res/fonts/sansation.ttf");

	m_prizeText.setPosition({ 640, 560 });
	m_prizeText.setFont(m_font);
	m_prizeText.setCharacterSize(40);

	m_prizeText.setString('1');
	auto centerY = m_prizeText.getLocalBounds().height / 2.0f;
	m_prizeText.setOrigin(0.0f, centerY);
}

void ResultController::calculatePrize()
{
	m_prize = 0;

	for (auto symbol : m_resultSymbols)
	{
		switch (symbol->getSymbolType())
		{
		case SymbolType::symbol_1:
			m_prize += 10;
			break;
		case SymbolType::symbol_2:
			m_prize += 5;
			break;
		case SymbolType::symbol_3:
			m_prize += 1;
			break;
		default:
			symbol->makeTransparent();
			break;
		}
	}
}

void ResultController::createPrizeText()
{
	if (m_prize == 0)
		return;

	m_prizeText.setString(std::to_string(m_prize));

	float centerX = m_prizeText.getLocalBounds().width / 2.0f;
	m_prizeText.setOrigin(centerX, m_prizeText.getOrigin().y);
}

void ResultController::draw(sf::RenderWindow & window) const
{
	if (m_prize == 0)
		return;

	m_prizeWindow.draw(window);
	window.draw(m_prizeText);
}
