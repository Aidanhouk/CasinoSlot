#include "Button/Button.h"

void Button::setData(const sf::Vector2f& position, const sf::Vector2f& size)
{
	setSize(size);
	setOrigin({ 0.5f,0.5f });
	setPosition(position);

	halfSizeX = size.x / 2.0f;
	halfSizeY = size.y / 2.0f;
}

bool Button::isInsideButton(const sf::Vector2i & mousePos)
{
	bool left = mousePos.x > getPosition().x - halfSizeX;
	bool right = mousePos.x < getPosition().x + halfSizeX;
	bool top = mousePos.y > getPosition().y - halfSizeY;
	bool bottom = mousePos.y < getPosition().y + halfSizeY;

	return (left && right && top && bottom);
}
