#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	float m_fSpeed;

	bool m_bHit;

	Projectile(float fX, float fY, float fSizeRadius, sf::Color cColor);

	void Move(float fDeltaTime, float fX, float fY);
};