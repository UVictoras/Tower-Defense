#include <iostream>
#include "GameObject.h"
#include "Math.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject()
{
	m_fDirection.x = NULL;
	m_fDirection.y = NULL;

	m_bType = NULL; // True -> Rectangle; False -> Circle
	m_fX = NULL;
	m_fY = NULL;
	m_fSizeH = NULL;
	m_fSizeL = NULL;
	m_sGraphism = NULL;
}

/*
-----------------------------------------------------------------------
|   Following are the methods corresponding to the GameObject Class   |
-----------------------------------------------------------------------
*/

GameObject::GameObject(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor)
{
	m_fDirection.x = 10.f;
	m_fDirection.y = -5.f;
	Math::Normalize(&m_fDirection.x, &m_fDirection.y);

	m_bType = bType; // True -> Rectangle; False -> Circle
	m_fX = fX;
	m_fY = fY;
	m_fSizeH = fSizeH;
	m_fSizeL = fSizeL;
	if (m_bType)
	{
		m_sGraphism = new sf::RectangleShape(sf::Vector2f(m_fSizeL, m_fSizeH));
	}
	else
	{
		m_sGraphism = new sf::CircleShape(m_fSizeL);
	}
	m_sGraphism->setPosition(m_fX, m_fY);
	m_sGraphism->setFillColor(cColor);
}

void GameObject::Draw(sf::RenderWindow* oWindow)
{
	if (m_sGraphism != nullptr)
		oWindow->draw(*m_sGraphism);
}