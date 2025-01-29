#include "Circle.h"
#include "LineRenderer.h"


Circle::Circle()
{
	pos = Vec2(0, 0);
	radius = 1.0f;
	inverseMass = 1.0f/ (radius * radius);
}

Circle::Circle(Vec2 _pos, float _radius)
{
	pos = _pos;
	radius = _radius;
	inverseMass = 1.0f/ (radius * radius);
}

void Circle::Draw()
{
	lines->DrawCircle(pos,radius,colour);
}
