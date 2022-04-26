#include "Field/Symbol/SymbolTexture.h"

sf::Texture SymbolTexture::textures[SymbolType::NUMBER_OF_SYMBOLS];
bool SymbolTexture::textureIsLoaded[SymbolType::NUMBER_OF_SYMBOLS]{ false };

sf::Texture & SymbolTexture::getTexture(int symbolIndex)
{
	if (!textureIsLoaded[symbolIndex])
	{
		textureIsLoaded[symbolIndex] = true;

		if (!textures[symbolIndex].loadFromFile("res/textures/symbols/symbol_" + std::to_string(symbolIndex + 1) + ".png")) {
			throw std::runtime_error("Unable to load texture: ");
		}
	}

	return textures[symbolIndex];
}