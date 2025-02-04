#pragma once
#include "PhysicsObject.h"

class Plane : public PhysicsObject
{
public:

	Vec2 normal;
	float displacement;

	Plane(Vec2 _normal, float _displacement);

	virtual void Draw(LineRenderer* lines) const override;
};