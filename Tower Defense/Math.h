#pragma once
class GameObject;

namespace Math
{
	void Normalize(float* fX, float* fY);

	float Rotate(GameObject* gGameObject, float vLocalPositionX, float vLocalPositionY);

	bool IsInsideInterval(int v, int vMin, int vMax);
};