#include "TextureManager.h"

TextureManager* TextureManager::tInstance = nullptr;

TextureManager::TextureManager()
{

}

/*
-----------------------------------------------------------------------
| Following are the methods corresponding to the TextureManager Class |
-----------------------------------------------------------------------
*/

void TextureManager::CreateTexture(const char* cImageName, sf::Texture* tTexture)
{

	if (!tTexture->loadFromFile(cImageName))
	{
		//Image not loaded
		return;
	}

	tTexture->setSmooth(true);
}