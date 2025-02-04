#pragma once

#include "CollisionInfo.h"

#include "PhysicsObject.h"
#include "Circle.h"
#include "Box2d.h"
#include "Plane.h"



CollisionInfo GetOverlap(PhysicsObject* a, PhysicsObject* b);

CollisionInfo OverlapCircleToCircle(Circle* a, Circle* b);
CollisionInfo OverlapBoxToBox(Box2d* a, Box2d* b);
CollisionInfo OverlapBoxToCircle(Box2d* a, Circle* b);
CollisionInfo OverlapCircleToPlane(Circle* a, Plane* b);
CollisionInfo OverlapBox2dToPlane(Box2d* a, Plane* b);