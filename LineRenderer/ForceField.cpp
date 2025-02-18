#include "ForceField.h"
#include "LineRenderer.h"

ForceField::ForceField(Vec2 _pos, Vec2 _normalForce, float _forceStrength, float w, float h) 
{
	pos = _pos;
	normalForce = _normalForce;
	ForceStrength = _forceStrength;
	width = w;
	height = h;
	inverseMass = 0;
}

ForceField::ForceField(Vec2 _pos, Vec2 _normalForce, float _forceStrength, float w, float h, Colour _colour) 
{
	pos = _pos;
	normalForce = _normalForce;
	ForceStrength = _forceStrength;
	width = w;
	height = h;
	inverseMass = 0;
	colour = _colour;
}

void ForceField::Draw(LineRenderer* lines) const
{
	Vec2 topLeft = pos + Vec2(-width, height) * 0.5f;
	Vec2 topRight = pos + Vec2(width, height) * 0.5f;
	Vec2 bottomRight = pos + Vec2(width, -height) * 0.5f;
	Vec2 bottomLeft = pos + Vec2(-width, -height) * 0.5f;

	lines->AddPointToLine(topLeft, colour);
	lines->AddPointToLine(topRight, colour);
	lines->AddPointToLine(bottomRight, colour);
	lines->AddPointToLine(bottomLeft, colour);

	lines->FinishLineLoop();

	lines->DrawLineWithArrow(pos, pos + normalForce *2, 1.0f);
}
