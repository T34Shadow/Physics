#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{

}

PhysicsObject::PhysicsObject(Vec2 _pos) :pos(_pos)
{
}

void PhysicsObject::Update(float _delta)
{
	Vec2 gravity{ 0.0f,-9.81f };
	Vec2 acc = gravity + forceAccumulator * inverseMass;

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


