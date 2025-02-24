#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	pos = Vec2(0, 0);
	vel = Vec2(0, 0);
	colour = Colour(1, 1, 1);
	forceAccumulator = Vec2(0, 0);
	inverseMass = 0.0f;
}

PhysicsObject::PhysicsObject(Vec2 _pos)
{
	pos = _pos;
}

PhysicsObject::~PhysicsObject()
{
}

void PhysicsObject::Update(float _delta)
{
	Vec2 gravity{ 0.0f,-9.81f };
	Vec2 acc = forceAccumulator * inverseMass;

	pos += vel * _delta;
	vel += acc * _delta;

	forceAccumulator = Vec2();
}

void PhysicsObject::AddForce(Vec2 force)
{
	forceAccumulator += force;
}

void PhysicsObject::AddImpules(Vec2 impulse)
{
	vel += impulse * inverseMass;
}



