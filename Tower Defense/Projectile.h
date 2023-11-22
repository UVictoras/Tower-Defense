#pragma once
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	float m_fSpeed;

	bool m_bHit;

	int m_iEnemyIndex;

	Projectile(float fX, float fY, float fSizeRadius, sf::Color cColor, int iClosestEnemyIndex, const char* cFileName);

	void Move(float fDeltaTime, sf::Vector2f fDirection);
};