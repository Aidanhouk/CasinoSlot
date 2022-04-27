#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Sprite
{
public:
	void loadFromFile(const std::string& fileName);

	void setPosition(const sf::Vector2f& position);

	void draw(sf::RenderWindow& window) const;

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};