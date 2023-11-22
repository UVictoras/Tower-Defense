#include "Projectile.h"

Projectile::Projectile(float fX, float fY, float fSizeRadius, sf::Color cColor, int iClosestEnemyIndex, const char* cFileName) : GameObject(fX, fY, fSizeRadius, cColor, cFileName)
{
	m_fSpeed = 2000.f;
	m_bHit = false;
}

void Projectile::Move(float fDeltaTime, sf::Vector2f fDirection)
{
	
	ChangeDirection(fDirection);
	m_fX += fDeltaTime * m_fSpeed * m_fDirection.x;
	m_fY += fDeltaTime * m_fSpeed * m_fDirection.y;
	m_sGraphism->setPosition(m_fX, m_fY);
}