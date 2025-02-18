#pragma once

#include "Application.h"
#include "Maths.h"

class Example : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	Vec2 pos{ 4.0f,4.0f };
	Vec2 vel{ 4.0f,7.0f };
	Vec2 acc{0.0f, -1.81f };

public:
	Example();
	void Initialise() override;

	void Update(float delta) override;

};