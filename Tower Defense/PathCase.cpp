#include "PathCase.h"

PathCase::PathCase(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, char cDirection) : GameObject(fX, fY, fSizeW, fSizeH, cColor)
{
	m_cDirection = cDirection;
}