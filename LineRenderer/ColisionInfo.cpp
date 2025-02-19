#include "CollisionInfo.h"
#include "Circle.h"


void CollisionInfo::Resolve()
{
	if (!IsOverLapping()) return;

	float totalInverseMass = objectA->GetInverseMass() + objectB->GetInverseMass();

	objectB->GetPos() += collisionNormal * overlapAmount * objectB->GetInverseMass() / totalInverseMass;
	objectA->GetPos() -= collisionNormal * overlapAmount * objectA->GetInverseMass() / totalInverseMass;

	float elasticity = 0.74f;

	float j = (1 + elasticity) * Dot((objectA->GetVel() - objectB->GetVel()), collisionNormal) / totalInverseMass;

	objectA->AddImpules(-collisionNormal * j);
	objectB->AddImpules(collisionNormal * j);	

}
