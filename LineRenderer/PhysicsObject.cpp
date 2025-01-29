#include "PhysicsObject.h"
#include "LineRenderer.h"

PhysicsObject::PhysicsObject()
{

	pos = Vec2(0, 0);
	size = 0.5f;
	colour = Colour(1.0f, 1.0f, 1.0f);
}

PhysicsObject::PhysicsObject(Vec2 _pos, float _size)
{
	pos = _pos;
	size = _size;
}

PhysicsObject::PhysicsObject(Vec2 _pos, float _size, Colour _colour)
{
	pos = _pos;
	size = _size;
	colour = _colour;
}

void PhysicsObject::Update(float delta)
{
	pos += vel;
	vel += acc;
}

void PhysicsObject::Draw(Vec2 _pos, float _size, Colour _colour)
{
	lines->DrawCircle(_pos, _size, _colour);
}

void PhysicsObject::SetPos(Vec2 _pos)
{
	pos = _pos;
}

void PhysicsObject::SetSize(float _size)
{
	size = _size;
}

void PhysicsObject::SetColour(Colour _colour)
{
	colour = _colour;
}
