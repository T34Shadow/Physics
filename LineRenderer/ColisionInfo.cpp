#include "CollisionInfo.h"
#include "Circle.h"


void CollisionInfo::Resolve()
{
	if (!IsOverLapping()) return;

	float totalInverseMass = objectA->inverseMass + objectB->inverseMass;

	objectB->pos += collisionNormal * overlapAmount * objectB->inverseMass / totalInverseMass;
	objectA->pos -= collisionNormal * overlapAmount * objectA->inverseMass / totalInverseMass;

	float elasticity = 1.0f;

	float j = (1 + elasticity) * Dot((objectA->vel - objectB->vel), collisionNormal) / totalInverseMass;

	objectA->AddImpules(-collisionNormal * j);
	objectB->AddImpules(collisionNormal * j);

}
