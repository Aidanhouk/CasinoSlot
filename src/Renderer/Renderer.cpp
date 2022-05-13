#include "Renderer/Renderer.h"

Renderer::Renderer()
{
	m_background.loadFromFile("slot_background");
	m_foreground.loadFromFile("slot_foreground");
}

void Renderer::drawBackground(sf::RenderWindow& window) const
{
	m_background.draw(window);
}

void Renderer::drawForeground(sf::RenderWindow& window) const
{
	m_foreground.draw(window);
}
