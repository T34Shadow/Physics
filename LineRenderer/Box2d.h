#pragma once

#include <float.h>
#include "PhysicsObject.h"
#include "Vec2.h"

class LineRenderer;

//This class isn't well-suited to work alongside the circle class because it doesn't
//get defined in terms of position.
class Box2d : PhysicsObject
{
public:
	float xMin = FLT_MAX;
	float xMax = -FLT_MAX;
	float yMin = FLT_MAX;
	float yMax = -FLT_MAX;

	Box2d(Vec2 p1, Vec2 p2);

	void Draw(LineRenderer* lines) const;

};