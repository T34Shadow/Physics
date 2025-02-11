#pragma once

#include "PhysicsObject.h"

class LineRenderer;

class Box2d : public PhysicsObject
{
public:

	float width = 1.0f;
	float height = 1.0f;

	Box2d(Vec2 _pos, float w, float h);
	Box2d(Vec2 _pos, float w, float h, Colour _colour);

	virtual void Draw(LineRenderer* lines) const override;

};