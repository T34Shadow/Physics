#pragma once
#include "Application.h"
#include "PhysicsObject.h"
#include "vector"

class Circle;
class PhysicsEnvro : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	std::vector<PhysicsObject*> physicsObjects{ 10 };
	LineRenderer* Lines;

public:
	PhysicsEnvro();
	void Initialise() override;

	void Update(float delta) override;

};