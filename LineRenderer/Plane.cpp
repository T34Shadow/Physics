#include "Plane.h"
#include "LineRenderer.h"

Plane::Plane(Vec2 _normal, float _displacement) : PhysicsObject(_normal)
{
	displacement = _displacement;
	normal = _normal;
	inverseMass = 0;
	vel = Vec2(0,0);
	//acc = Vec2(0, 0);

	normal.Normalise();

}

Plane::Plane(Vec2 _normal, float _displacement, Colour _colour) : PhysicsObject(_normal)
{
	displacement = _displacement;
	normal = _normal;
	inverseMass = 0;
	colour = _colour;
	vel = Vec2(0, 0);
	//acc = Vec2(0, 0);

	normal.Normalise();
}

void Plane::Draw(LineRenderer* lines) const
{
	Vec2 tanget = normal.GetRotatedBy90();

	Vec2 planeOrigin = normal * displacement;
	float scale = 1;
	scale = (planeOrigin).GetMagnitude();
	Vec2 start = planeOrigin - tanget *scale;
	Vec2 end = planeOrigin + tanget *scale;

	lines->DrawLineSegment(start, end, colour);
	lines->DrawLineWithArrow(planeOrigin, planeOrigin + normal, 0.5f);
}
