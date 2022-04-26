#pragma once

#include <SFML/Graphics.hpp>

class Button : public sf::RectangleShape
{
public:
	void setData(const sf::Vector2f& position, const sf::Vector2f& size);

	bool isInsideButton(const sf::Vector2i& mousePos);
private:
	float halfSizeX, halfSizeY;
};