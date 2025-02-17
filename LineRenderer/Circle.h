#pragma once

#include "PhysicsObject.h"

class Circle : public PhysicsObject
{
public:

	float radius;

	Circle(Vec2 _pos, float _radius);
	Circle(Vec2 _pos, float _radius,Colour _colour);

	virtual void Draw(LineRenderer* lines) const override;

};