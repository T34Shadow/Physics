#pragma once
#include "Colour.h"
#include "Vec2.h"

class LineRenderer;

class PhysicsObject 
{

public:

	Vec2 pos;
	Vec2 vel{ 0.0f,-0.1f };
	
	Vec2 forceAccumulator;
	//Vec2 acc;

	float inverseMass;	
	Colour colour;

	LineRenderer* lines = nullptr;

	PhysicsObject(Vec2 _pos);

	void Update(float _delta);
	virtual void Draw(LineRenderer* lines) const =0;

	void AddForce();
	void AddImpules();
};