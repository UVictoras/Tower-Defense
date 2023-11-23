#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, const char* sFileName, int iLife) : GameObject(fX, fY, fSizeW, fSizeH, cColor, sFileName)
{
	m_fSpeed = 10.f;
	m_iHP = iLife;
	m_iPathIndex = 0;
}

void Enemy::MoveAlongPath(PathCase* cPathCase, float fDeltaTime)
{
	if (cPathCase->m_cDirection == 'R') // Right
	{
		m_fDirection = { 1.f, 0.f };
	}
	else if (cPathCase->m_cDirection == 'T') // Top
	{
		m_fDirection = { 0.f, -1.f };
	}
	else if (cPathCase->m_cDirection == 'D') // Down
	{
		m_fDirection = { 0.f, 1.f };
	}
	else if (cPathCase->m_cDirection == 'L') // Left
	{
		m_fDirection = { -1.f, 0.f };
	}
	m_sGraphism->setPosition(m_fX, m_fY);
}

void Enemy::TakeDamage(Projectile* pProjectile, int iDamage)
{
	m_iHP -= iDamage;
	pProjectile->m_bHit = true;
	pProjectile->m_sGraphism = nullptr;
}

void Enemy::Hit(Projectile* pProjectile, int iDamage)
{
	if (m_sGraphism != nullptr and pProjectile->m_sGraphism != nullptr)
	{
		if (pProjectile->m_sGraphism->getGlobalBounds().intersects(m_sGraphism->getGlobalBounds()))
		{
			TakeDamage(pProjectile, iDamage);
		}
	}
}

void Enemy::StartMove(float fDeltaTime)
{
	m_fX += 5.f * m_fSpeed * fDeltaTime;
}

void Enemy::Die()
{
	if (m_iHP <= 0)
	{
		m_sGraphism = nullptr;
	}
}

bool Enemy::HitCastle()
{
    if (m_fY >= 1000)
    {
        m_sGraphism = nullptr;
		return true;
    }
	return false;
}

void Enemy::Move(float fDeltaTime)
{
	m_fY += 10.f * m_fSpeed * fDeltaTime * m_fDirection.y;
	m_fX += 10.f * m_fSpeed * fDeltaTime * m_fDirection.x;
}