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
	LineRenderer* Lines;
	Plane* testPlane01;
	Plane* testPlane02;
	Plane* testPlane03;
	Plane* testPlane04;



public:
	PhysicsEnvro();
	void Initialise() override;

	void Update(float delta) override;

};