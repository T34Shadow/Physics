#include "PhysicsEnvro.h"
#include "LineRenderer.h"
#include "CollisionFunctions.h"
#include "Box2d.h"
#include "Circle.h"
#include "ForceField.h"
#include "Plane.h"

#include "TextStream.h"

#include <iostream>
#include <random>

PhysicsEnvro::PhysicsEnvro()
{
	worldSize = 100.0f;
	appInfo.grid.extent = (int)worldSize;
	appInfo.grid.show = false;
	appInfo.grid.unit = 1;
	appInfo.appName = "PHYSICS ENGINE";
}

void PhysicsEnvro::Initialise()
{
	worldBoarders[0]=(new Plane(Vec2(0, -1), worldSize, Colour::RED));
	worldBoarders[1]=(new Plane(Vec2(1, 0), worldSize, Colour::BLUE));
	worldBoarders[2]=(new Plane(Vec2(0, 1), worldSize, Colour::GREEN));
	worldBoarders[3]=(new Plane(Vec2(-1, 0), worldSize, Colour::YELLOW));

	objectHeld = false;
	physicsObjects.push_back(new Box2d(Vec2(0, 50), 2, 2, Colour::CYAN));

	for (int i = 0; i < 10; i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 100;
		randPos.y = (rand() / (float)RAND_MAX) * 50;
		physicsObjects.push_back(new Circle(randPos, 2));
	}
	for (int i = 0; i < 10; i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 50;
		randPos.y = (rand() / (float)RAND_MAX) * 100;
		physicsObjects.push_back(new Box2d(randPos, 1.7f,1.7f));
	}
	windTunnels.push_back(new ForceField(Vec2(0.0f, -85.0f), Vec2(0.0f, 1.0f), 100.0f, 100.0f, 10.0f,Colour::MAGENTA));
	windTunnels.push_back(new ForceField(Vec2(0.0f, 85.0f), Vec2(0.0f, -1.0f), 100.0f, 100.0f, 10.0f,Colour::MAGENTA));
	windTunnels.push_back(new ForceField(Vec2(85.0f, 0.0f), Vec2(-1.0f, 0.0f), 100.0f, 10.0f, 100.0f,Colour::MAGENTA));
	windTunnels.push_back(new ForceField(Vec2(-85.0f, 0.0f), Vec2(1.0f, 0.0f), 100.0f, 10.0f, 100.0f,Colour::MAGENTA));
}

void PhysicsEnvro::OnRightClick()
{
	objectHeld = true;
}

void PhysicsEnvro::OnRightRelease()
{
	objectHeld = false;
}

void PhysicsEnvro::Update(float delta)
{
	//PHYSICS UPDATE
	//-----------------------------------------------------------------------------
	
	if (objectHeld)
	{
		physicsObjects[0]->vel = (previousPos - cursorPos) / delta;
		physicsObjects[0]->pos = cursorPos;
		previousPos = cursorPos;
	}
	
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
		for (int j = 0; j < windTunnels.size(); j++)
		{
			CollisionInfo thisHit = GetOverlap(physicsObjects[i], windTunnels[j]);
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
	for (PhysicsObject* thisObject : windTunnels)
	{
		thisObject->Draw(lines);
	}
}


