#pragma once
#include "Application.h"
#include "PhysicsObject.h"
#include "vector"
class Plane;
class Box2d;

class PhysicsEnvro : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	std::vector<PhysicsObject*> physicsObjects;
	std::vector<PhysicsObject*> windTunnels;
	std::vector<Plane*> worldBoarders{ 4 };
	float worldSize;
	Vec2 previousPos;
	bool objectHeld;

public:
	PhysicsEnvro();
	void Initialise() override;
	void OnRightClick() override;
	void OnRightRelease() override;
	void Update(float delta) override;

};