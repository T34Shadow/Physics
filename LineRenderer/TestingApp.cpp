#include "TestingApp.h"
#include "LineRenderer.h"
#include <iostream>

#include <random>

TestingApp::TestingApp()
{
	float randomNumber = rand() / (float)RAND_MAX;
}

void TestingApp::Initialise()
{

	PlayerObject = new PhysicsObject(Vec2(0, 0), 0.3f, Colour(0, 0, 1));

	//populate the vector of physics object.


	for (int i = 0; i < physicsObjects.size(); i++)
	{
		Vec2 randPos;
		randPos.x = (rand() / (float)RAND_MAX) * 10;
		randPos.y = (rand() / (float)RAND_MAX) * 10;

		physicsObjects[i] = new PhysicsObject(randPos, 0.3f, Colour(1, 1, 1));
		physicsObjects[i]->lines = lines;
	}
}

void TestingApp::Update(float delta)
{
	//Phyics Update.
	// --------------------------------------------------------------------
	//collision resolution with player object to sence objects.
	PlayerObject->SetPos(cursorPos);

	for (int i = 0; i < physicsObjects.size(); i++)
	{
		float overlap = (physicsObjects[i]->GetPos() - PlayerObject->GetPos()).GetMagnitude();
		if (overlap <= physicsObjects[i]->GetSize() + PlayerObject->GetSize())
		{
			Vec2 newPos = physicsObjects[i]->GetPos() + (physicsObjects[i]->GetPos() - PlayerObject->GetPos()) * delta;

			physicsObjects[i]->SetPos(newPos);

			physicsObjects[i]->SetColour(Colour(1, 0, 0));
		}
		else
		{
			physicsObjects[i]->SetColour(Colour(1, 1, 1));
		}
	}

	///collision resolution of each physicsObjects with other physicsObjects.

	for (int i = 0; i < physicsObjects.size(); i++)
	{
		for (int j = 0; j < physicsObjects.size(); j++)
		{
			float overlap = (physicsObjects[i]->GetPos() - physicsObjects[j]->GetPos()).GetMagnitude();
			if (overlap <= physicsObjects[i]->GetSize() + physicsObjects[j]->GetSize())
			{
				Vec2 newPos = physicsObjects[i]->GetPos() + (physicsObjects[i]->GetPos() - physicsObjects[j]->GetPos()) * delta;

				physicsObjects[i]->SetPos(newPos);

				physicsObjects[i]->SetColour(Colour(1, 0, 1));
			}
			else
			{
				physicsObjects[i]->SetColour(Colour(1, 1, 1));
			}
		}
	}

	//Drawing Update.
	// --------------------------------------------------------------------
	lines->DrawCircle(PlayerObject->GetPos(), PlayerObject->GetSize(), PlayerObject->GetColour());

	for (int i = 0; i < physicsObjects.size(); i++)
	{
		physicsObjects[i]->Draw(physicsObjects[i]->GetPos(), physicsObjects[i]->GetSize(), physicsObjects[i]->GetColour());
	}
}

