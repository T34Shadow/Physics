#include "PhysicsEnvro.h"
#include "LineRenderer.h"
#include "CollisionFunctions.h"
#include "Box2d.h"
#include "Circle.h"
#include <iostream>

#include <random>

PhysicsEnvro::PhysicsEnvro()
{
	Lines = lines;
}

void PhysicsEnvro::Initialise()
{
	int numberOfCircles = 5;
	int numberOfBoxes = 5;

	//make number of circles into the physicsObjects vector 
	for (int i = 0; i < numberOfCircles; i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 10;
		randPos.y = (rand() / (float)RAND_MAX) * 10;
	
		physicsObjects[i] = new Circle(randPos,0.3f);
		physicsObjects[i]->lines = Lines;
	}
	//make number of boxes into the physicsObjects vector 
	for (int i = numberOfCircles; i < physicsObjects.size(); i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 10;
		randPos.y = (rand() / (float)RAND_MAX) * 10;
	
		physicsObjects[i] = new Box2d(randPos,0.5f,0.5f);
		physicsObjects[i]->lines = Lines;
	}
	physicsObjects.push_back(new Circle (Vec2(0,0), 1.0f));
}

void PhysicsEnvro::Update(float delta)
{

	//PHYSICS UPDATE
	//-----------------------------------------------------------------------------
	physicsObjects.back()->pos = cursorPos;
	
	std::vector<CollisionInfo> collisions;
	for (int i = 0; i < physicsObjects.size(); i++)
	{
		for (int j = i + 1; j < physicsObjects.size(); j++)
		{
			CollisionInfo thisHit = GetOverlap(physicsObjects[i], physicsObjects[j]);
			if (thisHit.IsOverLapping()) collisions.push_back(thisHit);
		}
	}

	for (CollisionInfo& thisHit : collisions)
	{
		thisHit.Resolve();
	}

	//DRAW UPDATE
	//-----------------------------------------------------------------------------

	for (int i = 0; i < physicsObjects.size(); i++)
	{
		physicsObjects[i]->Draw(lines);
	}
}


