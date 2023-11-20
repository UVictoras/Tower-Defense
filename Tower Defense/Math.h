#pragma once
class GameObject;

namespace Math
{
	static const float fPi = 3.14159265359f;

	void Normalize(float* fX, float* fY);

	float Rotate(GameObject* gGameObject, float vLocalPositionX, float vLocalPositionY);

	bool IsInsideInterval(int v, int vMin, int vMax);
};