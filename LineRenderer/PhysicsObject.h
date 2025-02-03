#pragma once
#include "Colour.h"
#include "Vec2.h"

class LineRenderer;

class PhysicsObject 
{

public:

	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	float inverseMass;	
	Colour colour;

	LineRenderer* lines = nullptr;

	PhysicsObject(Vec2 _pos);

	virtual void Draw(LineRenderer* lines) const =0;
};