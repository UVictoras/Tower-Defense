#pragma once
#include "GameObject.h"
#include "Math.h"

class Tower : public GameObject
{
private:
	const float fSpeedAngular;

public:
	Tower(bool bType, float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor);

	void Rotate(float fDeltaTime);
};