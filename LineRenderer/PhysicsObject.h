#pragma once

#include "Application.h"
#include "Maths.h"

class LineRenderer;

class PhysicsObject
{
private:

protected:

	Vec2 pos;
	float inverseMass;	

public:

	Colour colour;
	Vec2 vel;
	Vec2 acc;

	LineRenderer* lines = nullptr;

	PhysicsObject();
	PhysicsObject(Vec2 _pos, float _inverseMass);

	void Update(float delta);
	virtual void Draw() =0;

	Vec2 GetPos() { return pos; }
	float GetInverseMass() { return inverseMass; }



};