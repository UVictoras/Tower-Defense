#include "Case.h"

Case::Case(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor) : GameObject(fX, fY, fSizeW, fSizeH, cColor)
{
	m_bIsFull = false;
}