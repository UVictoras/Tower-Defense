#pragma once
#include "GameObject.h"
#include "Math.h"

class Case : public GameObject
{
public:
	bool m_bIsFull;

	Case(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor);
};