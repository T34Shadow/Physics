#include "PhysicsObject.h"
#include "LineRenderer.h"

PhysicsObject::PhysicsObject()
{
	pos = Vec2(0, 0);
	inverseMass = 0.0f;
}

PhysicsObject::PhysicsObject(Vec2 _pos ,float _inverseMass)
{
	pos = _pos;
	inverseMass = _inverseMass;
}

void PhysicsObject::Update(float delta)
{
	pos += vel * delta;
	vel += acc * delta;
}

