#include "Tower.h"

Tower::Tower(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor, const char* cFileName) : GameObject(fX, fY, fSizeW, fSizeH, cColor, cFileName)
{
	m_fAngle = 0.f;
}

void Tower::Rotate(float fDeltaTime)
{
	m_fAngle += m_fSpeedAngular * fDeltaTime;
	if (m_fAngle > Math::DegToRad(360.f))
		m_fAngle -= Math::DegToRad(360.f);
}

void Tower::Shoot(float fX, float fY) 
{
	m_pProjectiles.push_back(new Projectile(m_fX + m_fSizeW / 2 - 15.f, m_fY - m_fSizeH * 0.000001f, 15.f, sf::Color::Green));

	m_pProjectiles[m_pProjectiles.size() - 1]->ChangeDirection({fX, fY});
}

void Tower::DeleteProjectile()
{
	for (int z = 0; z < m_pProjectiles.size(); z++)
	{
		if (m_pProjectiles[z]->m_sGraphism == nullptr)
		{
			m_pProjectiles.erase(m_pProjectiles.begin() + z);
		}
	}
}