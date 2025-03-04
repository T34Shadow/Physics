#pragma once

#include "PhysicsObject.h"

class LineRenderer;

class Box2d : public PhysicsObject
{
private:

	float width;
	float height;

public:

	Box2d(Vec2 _pos, float w, float h);
	Box2d(Vec2 _pos, float w, float h, Colour _colour);
	Box2d(Vec2 _pos, float w, float h, Colour _colour, bool _isStatic);
	~Box2d() = default;

	float& GetWidth() { return width; }
	float& GetHeight() { return height; }

	virtual void Draw(LineRenderer* lines) const override;

};