#pragma once
#include <vector>
#include "GameObject.h"
#include "Projectile.h"

class Tower : public GameObject
{
private:
	const float m_fSpeedAngular = Math::DegToRad(180.f);

	float m_fAngle;

	int m_iPrice;


public:
	float m_fDelay, m_fTimeElapsed, m_fRadius;

	std::vector<Projectile*> m_pProjectiles;

	Tower(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, const char* cFileName, float fRadius);

	void Rotate(float fDeltaTime);

	void Shoot(float fX, float fY, int iClosestEnemyIndex);

	void DeleteProjectile();
};