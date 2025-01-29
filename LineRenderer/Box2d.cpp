#include "Box2d.h"

#include "LineRenderer.h"
#include "Maths.h"

Box2d::Box2d(Vec2 p1, Vec2 p2)
{
	xMin = Min(p1.x, p2.x);
	xMax = Max(p1.x, p2.x);
	yMin = Min(p1.y, p2.y);
	yMax = Max(p1.y, p2.y);


}

void Box2d::Draw(LineRenderer* lines) const
{

	Vec2 topLeft(xMin, yMax);
	Vec2 topRight(xMax, yMax);
	Vec2 bottomRight(xMax, yMin);
	Vec2 bottomLeft(xMin, yMin);

	lines->AddPointToLine(topLeft);
	lines->AddPointToLine(topRight);
	lines->AddPointToLine(bottomRight);
	lines->AddPointToLine(bottomLeft);

	lines->FinishLineLoop();


}
