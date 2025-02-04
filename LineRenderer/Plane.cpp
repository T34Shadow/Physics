#include "Plane.h"
#include "LineRenderer.h"

Plane::Plane(Vec2 _normal, float _displacement) : PhysicsObject(_normal), displacement(_displacement)
{
	normal = _normal;
	inverseMass = 0;
	vel = Vec2(0,0);
	//acc = Vec2(0, 0);

	normal.Normalise();

}

void Plane::Draw(LineRenderer* lines) const
{
	Vec2 tanget = normal.GetRotatedBy90();

	Vec2 planeOrigin = normal * displacement;

	Vec2 start = planeOrigin - tanget *100;
	Vec2 end = planeOrigin + tanget *100;

	lines->DrawLineSegment(start, end, colour);
	lines->DrawLineWithArrow(planeOrigin, planeOrigin + normal, 0.5f);
}
