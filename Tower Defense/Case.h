#pragma once
#include "GameObject.h"
#include "Math.h"

class Case : public GameObject
{
public:
	bool bIsFull;

	Case(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);
};