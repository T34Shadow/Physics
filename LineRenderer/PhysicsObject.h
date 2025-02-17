#pragma once
#include "Colour.h"
#include "Vec2.h"

class LineRenderer;

class PhysicsObject 
{

public:

	Vec2 pos;
	Vec2 vel;
	Colour colour;
	Vec2 forceAccumulator;
	float inverseMass; // Having a inverse mass of 0 means it will be static.\
	
	//bool isTrigger = false; //For having physics objects to trigger an event and not have a physical responce.
	//bool isStatic = false; //For having physics objects to respond to collision with a stactic object.

	LineRenderer* lines = nullptr;

	PhysicsObject();
	PhysicsObject(Vec2 _pos);

	void Update(float _delta);
	virtual void Draw(LineRenderer* lines) const =0;

	void AddForce(Vec2 force);
	void AddImpules(Vec2 impulse);
};