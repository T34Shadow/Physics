#pragma once
#include "Colour.h"
#include "Vec2.h"

class LineRenderer;

class PhysicsObject 
{
protected:

	Vec2 pos;
	Vec2 vel;
	Colour colour;
	Vec2 forceAccumulator;
	float inverseMass; // Having a inverse mass of 0 means it will be static.
		
public:

	PhysicsObject();
	PhysicsObject(Vec2 _pos);
	~PhysicsObject();

	void Update(float _delta);
	virtual void Draw(LineRenderer* lines) const =0;

	void AddForce(Vec2 force);
	void AddImpules(Vec2 impulse);

	Vec2 &GetPos() { return pos ; }
	Vec2 &GetVel() { return vel; }
	Vec2& GetForceAcc() { return forceAccumulator; }
	float &GetInverseMass() { return inverseMass; }

};