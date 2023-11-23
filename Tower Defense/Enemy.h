#pragma once
#include "GameObject.h"
#include "PathCase.h"
#include "Projectile.h"

class Enemy : public GameObject
{
public:
	float m_fSpeed;

	int m_iHP, m_iPathIndex;
		
	bool iImmunePhysical;

	Enemy(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, const char* sFileName, int iLife);

	void MoveAlongPath(PathCase* pPathCase, float fDeltaTime);

	void TakeDamage(Projectile* pProjectile, int iDamage);

	void Hit(Projectile* pProjectile, int iDamage);

	void StartMove(float fDeltaTime);

	void Die();

    bool HitCastle();
	void Move(float fDeltaTime);
};