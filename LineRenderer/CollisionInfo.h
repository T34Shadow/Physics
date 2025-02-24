#pragma once

#include "Vec2.h"

class PhysicsObject;

class CollisionInfo
{
public:

	float overlapAmount;
	Vec2 collisionNormal;

	PhysicsObject* objectA;
	PhysicsObject* objectB;

	bool IsOverLapping() const { return overlapAmount > 0.0f; }
	void Resolve();
};