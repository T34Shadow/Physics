#include "CollisionFunctions.h"
#include "Maths.h"

CollisionInfo GetOverlap(PhysicsObject* a, PhysicsObject* b)
{
    Circle* circleA = dynamic_cast<Circle*>(a);
    if (circleA != nullptr)
    {
        Circle* circleB = dynamic_cast<Circle*>(b);
        if (circleB != nullptr)
        {
            return OverlapCircleToCircle(circleA, circleB);
        }
        Box2d* boxB = dynamic_cast<Box2d*>(b);
        if (boxB != nullptr)
        {
            return OverlapBoxToCircle(boxB, circleA);
        }
        //Plane* planeB = dynamic_cast<Plane*>(b);
        //if (planeB != nullptr)
        //{
        //    return OverlapCircleToPlane(circleA, planeB);
        //}
    }

    Box2d* boxA = dynamic_cast<Box2d*>(a);
    if (boxA != nullptr)
    {
        Circle* circleB = dynamic_cast<Circle*>(b);
        if (circleB != nullptr)
        {
            return OverlapBoxToCircle(boxA, circleB);

        }
        Box2d* boxB = dynamic_cast<Box2d*>(b);
        if (boxB != nullptr)
        {
            return OverlapBoxToBox(boxA, boxB);
        }
        //Plane* planeB = dynamic_cast<Plane*>(b);
        //if (planeB != nullptr)
        //{
        //    return OverlapBox2dToPlane(boxA, planeB);
        //}
    }

    return CollisionInfo();

}

CollisionInfo OverlapCircleToCircle(Circle* a, Circle* b)
{
    CollisionInfo info;
    info.objectA = a;
    info.objectB = b;
    Vec2 centreDisplacement = b->pos - a->pos;
    float distance = centreDisplacement.GetMagnitude();
    float separationOfSurfaces = distance - a->radius - b->radius;

    info.overlapAmount = -separationOfSurfaces;
    info.collisionNormal = centreDisplacement / distance;
    
    return info;
}

CollisionInfo OverlapBoxToBox(Box2d* a, Box2d* b)
{
    float aMinX = a->pos.x - a->width / 2.0f;
    float aMaxX = a->pos.x + a->width / 2.0f;
    float bMinX = b->pos.x - b->width / 2.0f;
    float bMaxX = b->pos.x + b->width / 2.0f;

    float aMinY = a->pos.y - a->height / 2.0f;
    float aMaxY = a->pos.y + a->height / 2.0f;
    float bMinY = b->pos.y - b->height / 2.0f;
    float bMaxY = b->pos.y + b->height / 2.0f;

    float overlapDepths[4];
    Vec2 overlapNormals[4];

    overlapDepths[0] = bMaxX - aMinX;
    overlapNormals[0] = Vec2(-1, 0);
    overlapDepths[1] = aMaxX - bMinX;
    overlapNormals[1] = Vec2(1, 0);

    overlapDepths[2] = bMaxY - aMinY;
    overlapNormals[2] = Vec2(0, -1);
    overlapDepths[3] = aMaxY - bMinY;
    overlapNormals[3] = Vec2(0, 1);

    int smallestIndex = 0;
    for (int i = 1; i < 4; i++)
    {
        if (overlapDepths[i] < overlapDepths[smallestIndex])
        {
            smallestIndex = i;
        }
    }

    CollisionInfo returnVal;
    returnVal.objectA = a;
    returnVal.objectB = b;
    returnVal.overlapAmount = overlapDepths[smallestIndex];
    returnVal.collisionNormal = overlapNormals[smallestIndex];
    return returnVal;
}

CollisionInfo OverlapBoxToCircle(Box2d* a, Circle* b)
{
    float aMinX = a->pos.x - a->width / 2.0f;
    float aMaxX = a->pos.x + a->width / 2.0f;

    float aMinY = a->pos.y - a->height / 2.0f;
    float aMaxY = a->pos.y + a->height / 2.0f;

    Vec2 closestPoint(Clamp(b->pos.x, aMinX, aMaxX), Clamp(b->pos.y, aMinY, aMaxY));

    CollisionInfo returnVal;
    returnVal.objectA = a;
    returnVal.objectB = b;    

    Vec2 centreDisplacement = b->pos - closestPoint;
    float distance = centreDisplacement.GetMagnitude();
    float separationOfSurfaces = distance - b->radius;

    returnVal.overlapAmount = -separationOfSurfaces;
    returnVal.collisionNormal = centreDisplacement / distance;

    return returnVal;
}

CollisionInfo OverlapCircleToPlane(Circle* a, Plane* b)
{
   // float dotProduct = Dot(testPlane02->normal, cursorPos);
   // lines->DrawCircle(cursorPos, 0.3f, dotProduct < testPlane02->displacement + 0.3f ? Colour::RED : Colour::WHITE);
    CollisionInfo returnVal;

    float dotProduct = Dot(b->normal, a->pos);
    returnVal.overlapAmount = a->radius - dotProduct;
    returnVal.collisionNormal = b->normal.Normalise();
    return returnVal;
}

CollisionInfo OverlapBox2dToPlane(Box2d* a, Plane* b)
{
    CollisionInfo returnVal;
    return returnVal;
}



