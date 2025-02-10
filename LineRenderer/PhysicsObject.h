#pragma once
#include "Colour.h"
#include "Vec2.h"

class LineRenderer;

class PhysicsObject 
{

public:

	Vec2 pos;
	Vec2 vel;
	
	Vec2 forceAccumulator;

	float inverseMass;	
	Colour colour;

	LineRenderer* lines = nullptr;

	PhysicsObject(Vec2 _pos);

	void Update(float _delta);
	virtual void Draw(LineRenderer* lines) const =0;

	void AddForce(Vec2 force);
	void AddImpules(Vec2 impulse);
};