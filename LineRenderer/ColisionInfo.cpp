#include "CollisionInfo.h"
#include "Circle.h"


void CollisionInfo::Resolve()
{
	if (!IsOverLapping()) return;

	float totalInverseMass = objectA->inverseMass + objectB->inverseMass;

	objectB->pos += collisionNormal * overlapAmount * objectB->inverseMass / totalInverseMass;
	objectA->pos -= collisionNormal * overlapAmount * objectA->inverseMass / totalInverseMass;



}
