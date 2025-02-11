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
	bool isTrigger = false;
	float inverseMass;	
	Colour colour;

	LineRenderer* lines = nullptr;

	PhysicsObject();
	PhysicsObject(Vec2 _pos);
	PhysicsObject(Vec2 _pos,bool _isTrigger);

	void Update(float _delta);
	virtual void Draw(LineRenderer* lines) const =0;

	void AddForce(Vec2 force);
	void AddImpules(Vec2 impulse);
};