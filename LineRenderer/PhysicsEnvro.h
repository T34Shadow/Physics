#pragma once
#include "Application.h"
#include "PhysicsObject.h"
#include "vector"
class Plane;

class PhysicsEnvro : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	std::vector<PhysicsObject*> physicsObjects;
	std::vector<Plane*> worldBoarders{ 4 };
	float worldSize;
	Vec2 previousPos;

public:
	PhysicsEnvro();
	void Initialise() override;

	void Update(float delta) override;

};