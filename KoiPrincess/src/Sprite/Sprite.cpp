#include "Sprite/Sprite.h"

#include "Config/Config.h"

#include <iostream>

void Sprite::loadFromFile(const std::string & fileName)
{
	if (!m_texture.loadFromFile("res/textures/" + fileName + ".png")) {
		throw std::runtime_error("Unable to load texture: " + fileName);
	}

	m_sprite.setTexture(m_texture);
}

void Sprite::setPosition(const sf::Vector2f & position)
{
	auto textureSize = m_sprite.getTexture()->getSize();
	m_sprite.setOrigin({ textureSize.x / 2.0f, textureSize.y / 2.0f });
	m_sprite.setPosition(position);
}

void Sprite::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
