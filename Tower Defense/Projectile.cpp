#include "Projectile.h"

Projectile::Projectile(float fX, float fY, float fSizeRadius, sf::Color cColor) : GameObject(fX, fY, fSizeRadius, cColor)
{
	m_fSpeed = 2000.f;
	m_bHit = false;
}

void Projectile::Move(float fDeltaTime, float fX, float fY){
	ChangeDirection({ fX, fY });
	m_fX += fDeltaTime * m_fSpeed * m_fDirection.x;
	m_fY += fDeltaTime * m_fSpeed * m_fDirection.y;
	m_sGraphism->setPosition(m_fX, m_fY);
}