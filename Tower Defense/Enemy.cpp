#include "Enemy.h"

Enemy::Enemy(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor) : GameObject(fX, fY, fSizeW, fSizeH, cColor)
{
	m_fSpeed = 10.f;
	m_iHP = 10;
	m_iPathIndex = -1;
}

void Enemy::MoveAlongPath(PathCase* cPathCase, float fDeltaTime)
{
	if (cPathCase->m_cDirection == 'R') // Right
	{
		if (m_fY + m_fSizeH / 2 < cPathCase->m_fY + cPathCase->m_fSizeH / 2)
		{
			m_fY += 10.f * m_fSpeed * fDeltaTime;
		}
		else if (m_fY + m_fSizeH / 2 > cPathCase->m_fY + cPathCase->m_fSizeH / 2)
		{
			m_fY -= 10.f * m_fSpeed * fDeltaTime;
		}
		else
		{
			m_fX += 10.f * m_fSpeed * fDeltaTime;
			m_iPathIndex++;
		}	
	}
	else if (cPathCase->m_cDirection == 'T') // Top
	{
		if (m_fX + m_fSizeW / 2 < cPathCase->m_fX + cPathCase->m_fSizeW / 2)
		{
			m_fX += 10.f * m_fSpeed * fDeltaTime;
		}
		else if (m_fX + m_fSizeW / 2 > cPathCase->m_fX + cPathCase->m_fSizeW / 2)
		{
			m_fX -= 10.f * m_fSpeed * fDeltaTime;
		}
		else
		{
			m_fY -= 10.f * m_fSpeed * fDeltaTime;
			m_iPathIndex++;
		}	
	}
	else if (cPathCase->m_cDirection == 'D') // Down
	{
		if (m_fX + m_fSizeW / 2 < cPathCase->m_fX + cPathCase->m_fSizeW / 2)
		{
			m_fX += 10.f * m_fSpeed * fDeltaTime;
		}
		else if (m_fX + m_fSizeW / 2 > cPathCase->m_fX + cPathCase->m_fSizeW / 2)
		{
			m_fX -= 10.f * m_fSpeed * fDeltaTime;
		}
		else
		{
			m_fY += 10.f * m_fSpeed * fDeltaTime;
			m_iPathIndex++;
		}
	}
	else if (cPathCase->m_cDirection == 'L') // Left
	{
		if (m_fY + m_fSizeH / 2 < cPathCase->m_fY + cPathCase->m_fSizeH / 2)
		{
			m_fY += 10.f * m_fSpeed * fDeltaTime;
		}
		else if (m_fY + m_fSizeH / 2 > cPathCase->m_fY + cPathCase->m_fSizeH / 2)
		{
			m_fY -= 10.f * m_fSpeed * fDeltaTime;
		}
		{
			m_fX -= 10.f * m_fSpeed * fDeltaTime;
			m_iPathIndex++;
		}	
	}
	m_sGraphism->setPosition(m_fX, m_fY);
}

void Enemy::TakeDamage(Projectile* pProjectile)
{
	m_iHP--;
	pProjectile->m_bHit = true;
	pProjectile->m_sGraphism = nullptr;
}

void Enemy::Hit(Projectile* pProjectile)
{
	if ((OverLap(pProjectile->m_fX, pProjectile->m_fY) || OverLap(pProjectile->m_fX + pProjectile->m_fSizeW, pProjectile->m_fY - pProjectile->m_fSizeH)) && pProjectile->m_bHit == false)
	{
		TakeDamage(pProjectile);
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
    if (m_fX >= 1920)
    {
        m_sGraphism = nullptr;
		return true;
    }
	return false;
}