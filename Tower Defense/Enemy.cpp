#include "Enemy.h"

Enemy::Enemy(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor) : GameObject(fX, fY, fSizeW, fSizeH, cColor)
{
	m_fSpeed = 5;
	m_iHP = 10;
}

void Enemy::MoveAlongPath(PathCase* cPathCase, float fDeltaTime)
{
	if (cPathCase->m_cDirection == 'R')
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
		}	
	}
	else if (cPathCase->m_cDirection == 'T')
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
		}	
	}
	else if (cPathCase->m_cDirection == 'D')
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
		}
	}
	else if (cPathCase->m_cDirection == 'L')
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
		}	
	}
	m_sGraphism->setPosition(m_fX, m_fY);
}