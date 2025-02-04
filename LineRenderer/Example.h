#pragma once

#include "Application.h"
#include "Maths.h"

class Example : public Application
{
private:
	//Any data that should persist for the duration of your program,
	//declare it here.
	Vec2 pos{ 4,4 };
	Vec2 vel{ 4,7 };
	Vec2 acc{0, -1.81 };

public:
	Example();
	void Initialise() override;

	void Update(float delta) override;

};