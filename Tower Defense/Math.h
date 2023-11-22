#pragma once
class GameObject;

namespace Math
{
	static const float fPi = 3.14159265359f;

	void Normalize(float* fX, float* fY);

	float Rotate(GameObject* gGameObject, float vLocalPositionX, float vLocalPositionY);

	bool IsInsideInterval(float v, float vMin, float vMax);

	float RadToDeg(float fAngle);

	float DegToRad(float fAngle);

	bool IsInsideRange(float fCenterX, float fCenterY, float fX, float fY, float fRadius);

	float CalculateDistance(float fCenterX, float fCenterY, float fX, float fY);
};