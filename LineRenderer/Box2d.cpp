#include "Box2d.h"

#include "LineRenderer.h"
#include "Maths.h"

Box2d::Box2d(Vec2 _pos, float w, float h) : PhysicsObject(_pos), width(w), height(h)
{
	inverseMass = 1.0f / (width * height);
}

Box2d::Box2d(Vec2 _pos, float w, float h, Colour _colour) : PhysicsObject(_pos), width(w), height(h)
{
	inverseMass = 1.0f / (width * height);
	colour = _colour;
}

Box2d::Box2d(Vec2 _pos, float w, float h, Colour _colour, bool _isStatic) : PhysicsObject(_pos), width(w), height(h)
{
	if (_isStatic == true)
	{
		inverseMass = 0;
	}
	else
	{
		inverseMass = 1.0f / (width * height);
	}
	colour = _colour;
}
void Box2d::Draw(LineRenderer* lines) const
{
	Vec2 topLeft = pos + Vec2(-width, height) * 0.5f;
	Vec2 topRight = pos + Vec2(width, height) * 0.5f;
	Vec2 bottomRight = pos + Vec2(width, -height) * 0.5f;
	Vec2 bottomLeft = pos + Vec2(-width, -height) * 0.5f;

	lines->AddPointToLine(topLeft,colour);
	lines->AddPointToLine(topRight,colour);
	lines->AddPointToLine(bottomRight,colour);
	lines->AddPointToLine(bottomLeft,colour);

	lines->FinishLineLoop();

}



