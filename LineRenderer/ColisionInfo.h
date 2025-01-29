#pragma once

#include "PhysicsObject.h"
#include "Vec2.h"

class ColislionInfo
{
public:

	float overlapAmount;
	Vec2 collilionNormal;

	Vec2 GetOverlapAmount(PhysicsObject& a, PhysicsObject& b);

	bool IsOverLapping();
};