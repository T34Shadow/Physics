#pragma once

#include "PhysicsObject.h"
#include "Vec2.h"

class Circle : PhysicsObject
{
public:

	Circle();
	Circle(Vec2 _pos, float _radius);

	void Draw();

private:

	float radius;
	
};