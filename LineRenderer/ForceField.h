#pragma once
#include "Box2d.h"

class LineRenderer;

class ForceField : public PhysicsObject
{
private:
	float width;
	float height;
	Vec2 normalForce;
	float ForceStrength;
public:

	ForceField() = default;
	ForceField(Vec2 _pos, Vec2 _normalForce, float _forceStrength, float w, float h);
	ForceField(Vec2 _pos, Vec2 _normalForce, float _forceStrength, float w, float h, Colour _colour);

	float& GetWidth() { return width; }
	float& GetHeight() { return height; }
	Vec2 GetNormalForce() { return normalForce; }
	float GetForceStrength() { return ForceStrength; }

	virtual void Draw(LineRenderer* lines) const override;

};