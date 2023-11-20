#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
private:
	static TextureManager* tInstance;

public:
	static void Initialize()
	{
		TextureManager::tInstance = new TextureManager();
	}

	static TextureManager* Get()
	{
		return tInstance;
	}

public:
	TextureManager();

	void CreateTexture(const char* cImageName, sf::Texture* tTexture);
};