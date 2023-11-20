#pragma once
#include "Math.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace sf
{
	class Shape;
	class Color;
	class RenderWindow;
}

class GameObject
{
public:
	float m_fX, m_fY;
	float m_fSizeW, m_fSizeH, m_fRadius;
	sf::Vector2f m_fDirection;
	sf::Shape* m_sGraphism;
	sf::Texture m_tTexture;

	GameObject(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor);
	
	GameObject(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, const char* sFileName);

	GameObject(float fX, float fY, float fRadius, sf::Color cColor);

	void Draw(sf::RenderWindow* oWindow);

	bool OverLap(float fX, float fY);
};