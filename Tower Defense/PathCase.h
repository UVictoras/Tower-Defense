#pragma once
#include "GameObject.h"	

class PathCase : public GameObject
{
public:
	char m_cDirection;

	PathCase(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, char cDirection);
};