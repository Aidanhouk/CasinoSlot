#pragma once

#include "Sprite/Sprite.h"

class Renderer
{
public:
	Renderer();

	void drawBackground(sf::RenderWindow& window) const;
	void drawForeground(sf::RenderWindow& window) const;

private:
	Sprite m_background;
	Sprite m_foreground;
};