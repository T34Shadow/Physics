#pragma once

#include "PhysicsObject.h"
#include "Vec2.h"

class Circle : public PhysicsObject
{
public:

	float radius;

	Circle(Vec2 _pos, float _radius);

	virtual void Draw(LineRenderer* lines) const override;

};