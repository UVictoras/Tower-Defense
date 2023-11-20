#pragma once
#include "GameObject.h"

class Tower : public GameObject
{
private:
	const float m_fSpeedAngular = Math::DegToRad(180.f);

	float m_fAngle, m_fFireSpeed, m_fDamage, m_fRange;

	int m_iPrice;

public:
	Tower(float fX, float fY, float fSizeL, float fSizeH, sf::Color cColor, const char* cFileName);

	void Rotate(float fDeltaTime);
};