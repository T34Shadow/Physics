#pragma once

#include "PhysicsObject.h"

class Circle : public PhysicsObject
{
private:
	float radius;
public:

	Circle(Vec2 _pos, float _radius);
	Circle(Vec2 _pos, float _radius,Colour _colour);
	~Circle() = default;

	float& GetRadius() { return radius; }

	virtual void Draw(LineRenderer* lines) const override;

};