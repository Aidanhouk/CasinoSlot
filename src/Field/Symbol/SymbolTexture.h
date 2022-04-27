#pragma once

#include "Field/Symbol/SymbolType.h"

#include <SFML/Graphics.hpp>

class SymbolTexture
{
public:
	static sf::Texture& getTexture(int symbolIndex);

private:
	static sf::Texture textures[SymbolType::NUMBER_OF_SYMBOLS];
	static bool textureIsLoaded[SymbolType::NUMBER_OF_SYMBOLS];
};