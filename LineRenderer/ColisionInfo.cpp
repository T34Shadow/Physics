#include "ColisionInfo.h"

Vec2 ColislionInfo::GetOverlapAmount(PhysicsObject& a, PhysicsObject& b)
{
	float separationOfSurfaces = (a.GetPos() - b.GetPos()).GetMagnitude() - a.GetSize() - b.GetSize();
	return -separationOfSurfaces;
}

bool ColislionInfo::IsOverLapping()
{
	return false;
}
