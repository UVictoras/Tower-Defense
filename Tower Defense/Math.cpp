#include "Math.h"
#include <cmath>
#include "GameObject.h"

/*
-----------------------------------------------------------------------
|   Following are the functions corresponding to the Math Namespace   |
-----------------------------------------------------------------------
*/

void Math::Normalize(float* fX, float* fY)
{
	float xtmp = *fX;
	*fX /= sqrtf((xtmp * xtmp + *fY * *fY));
	*fY /= sqrtf((xtmp * xtmp + *fY * *fY));
}

float Math::Rotate(GameObject* gGameObject, float vLocalPositionX, float vLocalPositionY)
{
	return -atan2(vLocalPositionX - gGameObject->m_fX, vLocalPositionY - gGameObject->m_fY) * 180 / 3.14159;
}