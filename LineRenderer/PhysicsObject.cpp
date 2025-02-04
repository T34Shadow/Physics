#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(Vec2 _pos) : pos(_pos)
{

}

void PhysicsObject::Update(float _delta)
{
	Vec2 acc = forceAccumulator * inverseMass;

	pos += vel * _delta;
	vel += acc * _delta;

	forceAccumulator = Vec2();

}


