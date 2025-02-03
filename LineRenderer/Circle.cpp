#include "Circle.h"
#include "LineRenderer.h"

Circle::Circle(Vec2 _pos, float _radius) : PhysicsObject(_pos), radius(_radius)
{
	inverseMass = 1.0f / (radius * radius);
}

void Circle::Draw(LineRenderer* lines) const
{
	lines->DrawCircle(pos, radius, colour);
}