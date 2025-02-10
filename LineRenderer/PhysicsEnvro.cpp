#include "PhysicsEnvro.h"
#include "LineRenderer.h"
#include "CollisionFunctions.h"
#include "Box2d.h"
#include "Circle.h"
#include "Plane.h"

#include "TextStream.h"

#include <iostream>
#include <random>

PhysicsEnvro::PhysicsEnvro()
{
	worldSize = 100;
	appInfo.grid.extent = worldSize;
	appInfo.grid.show = false;
	appInfo.grid.unit = 1;
	appInfo.appName = "PHYSICS ENGINE";
}

void PhysicsEnvro::Initialise()
{
	worldBoarders[0]=(new Plane(Vec2(0, -1), -worldSize, Colour::RED));
	worldBoarders[1]=(new Plane(Vec2(1, 0), -worldSize, Colour::RED));
	worldBoarders[2]=(new Plane(Vec2(0, 1), -worldSize, Colour::RED));
	worldBoarders[3]=(new Plane(Vec2(-1, 0), -worldSize, Colour::RED));

}

void PhysicsEnvro::Update(float delta)
{
	//PHYSICS UPDATE
	//-----------------------------------------------------------------------------
	//physicsObjects[0]->vel = (previousPos - cursorPos) / delta;
	//physicsObjects[0]->pos = cursorPos;
	//previousPos = cursorPos;
	
	for (PhysicsObject* thisObject : physicsObjects)
	{
		thisObject->Update(delta);
	}
	std::vector<CollisionInfo> collisions;
	
	for (int i = 0; i < physicsObjects.size(); i++)
	{
		for (int j = i + 1; j < physicsObjects.size(); j++)
		{
			CollisionInfo thisHit = GetOverlap(physicsObjects[i], physicsObjects[j]);
			if (thisHit.IsOverLapping()) collisions.push_back(thisHit);
		}
		for (int j = 0; j < worldBoarders.size(); j++)
		{
			CollisionInfo thisHit = GetOverlap(physicsObjects[i], worldBoarders[j]);
			if (thisHit.IsOverLapping()) collisions.push_back(thisHit);
		}
	}
	for (CollisionInfo& thisHit : collisions)
	{
		thisHit.Resolve();
	}	
	collisions.clear();
	

	

	//DRAW UPDATE
	//-----------------------------------------------------------------------------
	
	for (PhysicsObject* thisObject : physicsObjects)
	{
		thisObject->Draw(lines);
	}
	for (Plane* thisObject : worldBoarders)
	{
		thisObject->Draw(lines);
	}
}


