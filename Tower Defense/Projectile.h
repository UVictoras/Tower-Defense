#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor);
};