#pragma once
#include "Box2d.h"

class LineRenderer;

class ForceField : public Box2d
{
public:

	float width;
	float height;
	Vec2 normalForce;
	float ForceStrength;

	ForceField() = default;
	ForceField(Vec2 _pos, Vec2 _normalForce, float _forceStrength, float w, float h);
	ForceField(Vec2 _pos, Vec2 _normalForce, float _forceStrength, float w, float h, Colour _colour);

	virtual void Draw(LineRenderer* lines) const override;

};