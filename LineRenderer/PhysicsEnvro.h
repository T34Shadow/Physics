#pragma once
#include "PhysicsObject.h"
#include "vector"

class PhysicsEnvro : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	std::vector<PhysicsObject*> physicsObjects{ 10 };
	PhysicsObject* PlayerObject;

public:
	PhysicsEnvro();
	void Initialise() override;

	void Update(float delta) override;

};