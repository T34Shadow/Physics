#pragma once
#include "PhysicsObject.h"
#include "vector"

class CircleOnject;

class TestingApp : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	std::vector<PhysicsObject*> physicsObjects{ 10 };
	PhysicsObject* PlayerObject;

public:
	TestingApp();
	void Initialise() override;

	void Update(float delta) override;

};
