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