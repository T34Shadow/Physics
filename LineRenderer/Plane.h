#pragma once
#include "PhysicsObject.h"

class Plane : public PhysicsObject
{
private:
	Vec2 normal;
	float displacement;
public:

	Plane(Vec2 _normal, float _displacement);
	Plane(Vec2 _normal, float _displacement, Colour _colour);

	Vec2& GetNormal() { return normal; }
	float& GetDisplacement() {return displacement;}

	virtual void Draw(LineRenderer* lines) const override;
};