#include "PhysicsEnvro.h"
#include "LineRenderer.h"
#include "CollisionFunctions.h"
#include "Box2d.h"
#include "Circle.h"
#include "Plane.h"
#include <iostream>

#include "TextStream.h"

#include <random>

PhysicsEnvro::PhysicsEnvro()
{
	Lines = lines;


}

void PhysicsEnvro::Initialise()
{
	int numberOfCircles = 5;
	int numberOfBoxes = 5;
	int numberOfPhysicsObjects = numberOfCircles + numberOfBoxes +2;

	testPlane01 = new Plane(Vec2(0, 1), -15);
	testPlane02 = new Plane(Vec2(0, -1), -15);
	testPlane03 = new Plane(Vec2(1, 0), -15);
	testPlane04 = new Plane(Vec2(-1, 0), -15);

	testPlane01->colour = Colour::RED;
	testPlane02->colour = Colour::GREEN;
	testPlane03->colour = Colour::BLUE;
	testPlane04->colour = Colour::YELLOW;


	//physicsObjects.push_back(new Box2d (Vec2(0,0), 1.0f,1.0f));
	physicsObjects.push_back(new Circle (Vec2(0,0), 1));
	//make number of circles into the physicsObjects vector 
	for (int i = 1; i < numberOfCircles; i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 10;
		randPos.y = (rand() / (float)RAND_MAX) * 10;
	
		physicsObjects.push_back(new Circle(randPos, 0.3f));
	}
	//make number of boxes into the physicsObjects vector 
	for (int i = numberOfCircles+1; i < numberOfPhysicsObjects; i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 10;
		randPos.y = (rand() / (float)RAND_MAX) * 10;
	
		physicsObjects.push_back(new Box2d(randPos,0.5f,0.5f));
	}
	physicsObjects.push_back(testPlane01);
	physicsObjects.push_back(testPlane02);
	physicsObjects.push_back(testPlane03);
	physicsObjects.push_back(testPlane04);
}

void PhysicsEnvro::Update(float delta)
{
	//PHYSICS UPDATE
	//-----------------------------------------------------------------------------
	physicsObjects[0]->pos = cursorPos;
	
	std::vector<CollisionInfo> collisions;
	for (int i = 0; i < physicsObjects.size(); i++)
	{
		for (int j = i + 1; j < physicsObjects.size(); j++)
		{
			CollisionInfo thisHit = GetOverlap(physicsObjects[i], physicsObjects[j]);
			if (thisHit.IsOverLapping()) collisions.push_back(thisHit);
		}
	}
	
	for (PhysicsObject* thisObject : physicsObjects)
	{
		thisObject->Update(delta);
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


