#pragma once
#include "PhysicsObject.h"

class Plane : public PhysicsObject
{
public:

	Vec2 normal;
	float displacement;
	Colour colour;

	Plane(Vec2 _normal, float _displacement);
	Plane(Vec2 _normal, float _displacement, Colour _colour);

	virtual void Draw(LineRenderer* lines) const override;
};