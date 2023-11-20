#include "Case.h"

Case::Case(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor) : GameObject(fX, fY, fSizeL, fSizeH, cColor)
{
	bIsFull = false;
}