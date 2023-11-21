#pragma once
#include "GameObject.h"
#include "PathCase.h"
#include "Projectile.h"

class Enemy : public GameObject
{
public:
	float m_fSpeed;

	int m_iHP;
		
	bool iImmunePhysical;

	Enemy(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor);

	void MoveAlongPath(PathCase* pPathCase, float fDeltaTime);

	void TakeDamage(Projectile* pProjectile);

	void Hit(Projectile* pProjectile);

	void Die();
};