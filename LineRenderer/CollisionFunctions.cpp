#include "CollisionFunctions.h"
#include "Maths.h"
#include <vector>
#include <algorithm>

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
        Plane* planeB = dynamic_cast<Plane*>(b);
        if (planeB != nullptr)
        {
            return OverlapCircleToPlane(circleA, planeB);
        }
        ForceField* forceFieldB = dynamic_cast<ForceField*>(b);
        if (forceFieldB != nullptr)
        {
            return OverlapCircleToForceField(circleA, forceFieldB);
        }
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
        Plane* planeB = dynamic_cast<Plane*>(b);
        if (planeB != nullptr)
        {
            return OverlapBox2dToPlane(boxA, planeB);
        }
        ForceField* forceFieldB = dynamic_cast<ForceField*>(b);
        if (forceFieldB != nullptr)
        {
            return OverlapBox2dToForceField(boxA, forceFieldB);
        }
    }

    return CollisionInfo();

}

CollisionInfo OverlapCircleToCircle(Circle* a, Circle* b)
{
    CollisionInfo info;
    info.objectA = a;
    info.objectB = b;
    Vec2 centreDisplacement = b->GetPos() - a->GetPos();
    float distance = centreDisplacement.GetMagnitude();
    float separationOfSurfaces = distance - a->GetRadius() - b->GetRadius();

    info.overlapAmount = -separationOfSurfaces;
    info.collisionNormal = centreDisplacement / distance;
    
    return info;
}

CollisionInfo OverlapBoxToBox(Box2d* a, Box2d* b)
{
    float aMinX = a->GetPos().x - a->GetWidth() / 2.0f;
    float aMaxX = a->GetPos().x + a->GetWidth() / 2.0f;
    float bMinX = b->GetPos().x - b->GetWidth() / 2.0f;
    float bMaxX = b->GetPos().x + b->GetWidth() / 2.0f;

    float aMinY = a->GetPos().y - a->GetHeight() / 2.0f;
    float aMaxY = a->GetPos().y + a->GetHeight() / 2.0f;
    float bMinY = b->GetPos().y - b->GetHeight() / 2.0f;
    float bMaxY = b->GetPos().y + b->GetHeight() / 2.0f;

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
    float aMinX = a->GetPos().x - a->GetWidth() / 2.0f;
    float aMaxX = a->GetPos().x + a->GetWidth() / 2.0f;

    float aMinY = a->GetPos().y - a->GetHeight() / 2.0f;
    float aMaxY = a->GetPos().y + a->GetHeight() / 2.0f;

    Vec2 closestPoint(Clamp(b->GetPos().x, aMinX, aMaxX), Clamp(b->GetPos().y, aMinY, aMaxY));
    
    CollisionInfo returnVal;
    returnVal.objectA = a;
    returnVal.objectB = b;    

    if (closestPoint.x != 0 && closestPoint.y != 0)
    {
        Vec2 centreDisplacement = b->GetPos() - closestPoint;

        float distance = centreDisplacement.GetMagnitude();
        float separationOfSurfaces = distance - b->GetRadius();

        if (distance <= 0)
        {            
            return returnVal;
        }

        returnVal.overlapAmount = -separationOfSurfaces;
        returnVal.collisionNormal = centreDisplacement / distance;

        return returnVal;
    }
    else
    {
        return returnVal;
    }
}

CollisionInfo OverlapCircleToPlane(Circle* a, Plane* b)
{
    CollisionInfo returnVal;
    
    returnVal.objectA = a;
    returnVal.objectB = b;
    
    float dotProduct = Dot(b->GetNormal(), a->GetPos());
    
    returnVal.overlapAmount = dotProduct + a->GetRadius() - b->GetDisplacement();
    returnVal.collisionNormal = b->GetNormal();

    return returnVal;
}

CollisionInfo OverlapBox2dToPlane(Box2d* a, Plane* b)
{
    CollisionInfo returnVal;

    returnVal.objectA = a;
    returnVal.objectB = b;

    float aMinX = a->GetPos().x - a->GetWidth() / 2.0f;
    float aMaxX = a->GetPos().x + a->GetWidth() / 2.0f;

    float aMinY = a->GetPos().y - a->GetHeight() / 2.0f;
    float aMaxY = a->GetPos().y + a->GetHeight() / 2.0f;

    Vec2 topRight(aMaxX, aMaxY);
    Vec2 topLeft(aMinX, aMaxY);
    Vec2 bottomRight(aMaxX, aMinY);
    Vec2 bottomLeft(aMinX, aMinY);

    //check for when these points are behind the plane using dot on each point. 
    //get the most deep point behind the plane for the overlapAmount.
    
    std::vector<float>overlaps;
    overlaps.push_back(Dot(b->GetNormal(), topRight) - b->GetDisplacement());
    overlaps.push_back(Dot(b->GetNormal(), topLeft) - b->GetDisplacement());
    overlaps.push_back(Dot(b->GetNormal(), bottomRight) - b->GetDisplacement());
    overlaps.push_back(Dot(b->GetNormal(), bottomLeft) - b->GetDisplacement());

    std::sort(overlaps.begin(), overlaps.end());

    returnVal.overlapAmount = overlaps[3];
    returnVal.collisionNormal = b->GetNormal();

    return returnVal;
}

CollisionInfo OverlapCircleToForceField(Circle* a, ForceField* b)
{
    float aMinX = b->GetPos().x - b->GetWidth() / 2.0f;
    float aMaxX = b->GetPos().x + b->GetWidth() / 2.0f;

    float aMinY = b->GetPos().y - b->GetHeight() / 2.0f;
    float aMaxY = b->GetPos().y + b->GetHeight() / 2.0f;

    Vec2 closestPoint(Clamp(a->GetPos().x, aMinX, aMaxX), Clamp(a->GetPos().y, aMinY, aMaxY));

    if (closestPoint.x != 0 && closestPoint.y != 0)
    {
        Vec2 centreDisplacement = a->GetPos() - closestPoint;

        float distance = centreDisplacement.GetMagnitude();
        float separationOfSurfaces = distance - a->GetRadius();

        if (separationOfSurfaces <= 0)
        {
            a->AddForce(b->GetNormalForce() * b->GetForceStrength());
        }
    }
    return CollisionInfo();
}

CollisionInfo OverlapBox2dToForceField(Box2d* a, ForceField* b)
{
    float aMinX = a->GetPos().x - a->GetWidth() / 2.0f;
    float aMaxX = a->GetPos().x + a->GetWidth() / 2.0f;
    float bMinX = b->GetPos().x - b->GetWidth() / 2.0f;
    float bMaxX = b->GetPos().x + b->GetWidth() / 2.0f;

    float aMinY = a->GetPos().y - a->GetHeight() / 2.0f;
    float aMaxY = a->GetPos().y + a->GetHeight() / 2.0f;
    float bMinY = b->GetPos().y - b->GetHeight() / 2.0f;
    float bMaxY = b->GetPos().y + b->GetHeight() / 2.0f;

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
    if (overlapDepths[smallestIndex] >= 0)
    {
        a->AddForce(b->GetNormalForce() * b->GetForceStrength());
    }
    return CollisionInfo();
}



