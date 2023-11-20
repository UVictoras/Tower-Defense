#pragma once
#include "GameObject.h"
#include "PathCase.h"

class Enemy : public GameObject
{
public:
	float m_fSpeed;

	int m_iHP;

	Enemy(float fX, float fY, float fSizeW, float fSizeH, sf::Color cColor);

	void MoveAlongPath(PathCase* pPathCase, float fDeltaTime);
};