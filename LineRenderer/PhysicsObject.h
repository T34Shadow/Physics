#pragma once

#include "Application.h"
#include "Maths.h"

class LineRenderer;

class PhysicsObject
{
private:

	Vec2 pos;
	float size;
	Colour colour;

	

public:

	Vec2 vel;
	Vec2 acc;

	LineRenderer* lines = nullptr;

	PhysicsObject();
	PhysicsObject(Vec2 _pos, float _size);
	PhysicsObject(Vec2 _pos, float _size, Colour _colour);

	void Update(float delta);
	void Draw(Vec2 _pos, float _size, Colour _colour);

	Vec2 GetPos() { return pos; }
	float GetSize() { return size; }
	Colour GetColour() { return colour; }

	void SetPos(Vec2 _pos);
	void SetSize(float _float);
	void SetColour(Colour _colour);


};