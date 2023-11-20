#include <iostream>
#include "GameObject.h"
#include <SFML/Graphics.hpp>

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the GameObject Class   |
-----------------------------------------------------------------------
*/

GameObject::GameObject(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor)
{
	m_fDirection.x = 10.f;
	m_fDirection.y = -5.f;
	Math::Normalize(&m_fDirection.x, &m_fDirection.y);

	m_fX = fX;
	m_fY = fY;
	m_fSizeH = fSizeH;
	m_fSizeL = fSizeL;

	m_sGraphism = new sf::RectangleShape(sf::Vector2f(m_fSizeL, m_fSizeH));
	m_sGraphism->setPosition(m_fX, m_fY);
	m_sGraphism->setFillColor(cColor);
}

GameObject::GameObject(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor, const char* sFileName)
{
	m_fDirection.x = 10.f;
	m_fDirection.y = -5.f;
	Math::Normalize(&m_fDirection.x, &m_fDirection.y);

	m_fX = fX;
	m_fY = fY;
	m_fSizeH = fSizeH;
	m_fSizeL = fSizeL;

	m_sGraphism = new sf::RectangleShape(sf::Vector2f(m_fSizeL, m_fSizeH));
	m_sGraphism->setPosition(m_fX, m_fY);
	TextureManager::Get()->CreateTexture(sFileName, &m_tTexture);
	m_sGraphism->setTexture(&m_tTexture);
}

GameObject::GameObject(float fX, float fY, float fRadius, sf::Color cColor)
{
	m_fDirection.x = 10.f;
	m_fDirection.y = -5.f;
	Math::Normalize(&m_fDirection.x, &m_fDirection.y);

	m_fX = fX;
	m_fY = fY;
	m_fRadius = fRadius;

	m_sGraphism = new sf::CircleShape(m_fRadius);
	m_sGraphism->setPosition(m_fX, m_fY);
	m_sGraphism->setFillColor(cColor);
}

void GameObject::Draw(sf::RenderWindow* oWindow)
{
	if (m_sGraphism != nullptr)
		oWindow->draw(*m_sGraphism);
}