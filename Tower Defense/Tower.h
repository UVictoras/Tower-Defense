#pragma once
#include <vector>
#include "GameObject.h"
#include "Projectile.h"

class Tower : public GameObject
{
private:
	const float m_fSpeedAngular = Math::DegToRad(180.f);

	float m_fAngle, m_fFireSpeed, m_fDamage, m_fRange;

	int m_iPrice;


public:
	float fDelay = 0.5f;

	float fTimeElapsed = 0;

	std::vector<Projectile*> m_pProjectiles;

	Tower(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, const char* cFileName);

	void Rotate(float fDeltaTime);

	void Shoot(float fX, float fY);

	void DeleteProjectile();
};