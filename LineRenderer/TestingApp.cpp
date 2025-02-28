//#include "TestingApp.h"
//#include "LineRenderer.h"
//#include "ApplicationHarness.h"
//#include <iostream>
//
//#include <random>
//
//TestingApp::TestingApp()
//{
//	appInfo.camera.disable = false;
//	float randomNumber = rand() / (float)RAND_MAX;
//}
//
//void TestingApp::Initialise()
//{
//
//	PlayerObject = new PhysicsObject(Vec2(0, 0), 0.3f, Colour(0, 0, 1));
//
//	//populate the vector of physics object.
//
//
//	for (int i = 0; i < physicsObjects.size(); i++)
//	{
//		Vec2 randPos;
//		randPos.x = (rand() / (float)RAND_MAX) * 10;
//		randPos.y = (rand() / (float)RAND_MAX) * 10;
//
//		physicsObjects[i] = new PhysicsObject(randPos, 0.3f, Colour(1, 1, 1));
//		physicsObjects[i]->lines = lines;
//	}
//}
//
//void TestingApp::Update(float delta)
//{
//	//Phyics Update.
//	// --------------------------------------------------------------------
//	//collision resolution with player object to sence objects.
//	PlayerObject->SetPos(cursorPos);
//	
//	//Vec2 displacement = (cursorPos - PlayerObject->GetPos()).GetNormalised();
//	//lines->DrawLineWithArrow(PlayerObject->GetPos(), displacement);
//	//PlayerObject->GetPos() += displacement * delta;
//
//	for (int i = 0; i < physicsObjects.size(); i++)
//	{
//		float overlap = (physicsObjects[i]->GetPos() - PlayerObject->GetPos()).GetMagnitude();
//		if (overlap < physicsObjects[i]->GetSize() + PlayerObject->GetSize())
//		{
//			//update vel rather then the pos of an object
//			//physicsObjects[i]->vel += physicsObjects[i]->GetPos() - PlayerObject->GetPos();
//
//			Vec2 newPos = physicsObjects[i]->GetPos() + (physicsObjects[i]->GetPos() - PlayerObject->GetPos().GetNormalised())*delta;
//			physicsObjects[i]->SetPos(newPos);
//
//			physicsObjects[i]->SetColour(Colour::RED);
//		}
//		else
//		{
//			physicsObjects[i]->SetColour(Colour::WHITE);
//		}
//	}
//
//	///collision resolution of each physicsObjects with other physicsObjects.
//
//	for (int i = 0; i < physicsObjects.size(); i++)
//	{
//		for (int j = i+1; j < physicsObjects.size(); j++)
//		{
//			float overlap = (physicsObjects[i]->GetPos() - physicsObjects[j]->GetPos()).GetMagnitude();
//			if (overlap <= physicsObjects[i]->GetSize() + physicsObjects[j]->GetSize())
//			{
//				//update vel rather then the pos of an object
//				
//				//Vec2 newPos = physicsObjects[i]->GetPos() + (physicsObjects[i]->GetPos() - physicsObjects[j]->GetPos()) * delta;
//				//physicsObjects[i]->SetPos(newPos);
//				
//				physicsObjects[i]->SetColour(Colour::YELLOW);
//				//std::cout << "object " << i << " has been hit" << std::endl;
//			}
//		}
//		physicsObjects[i]->Update(delta);
//	}
//
//	//Drawing Update.
//	// --------------------------------------------------------------------
//	lines->DrawCircle(PlayerObject->GetPos(), PlayerObject->GetSize(), PlayerObject->GetColour());
//
//	for (int i = 0; i < physicsObjects.size(); i++)
//	{
//		physicsObjects[i]->Draw(physicsObjects[i]->GetPos(), physicsObjects[i]->GetSize(), physicsObjects[i]->GetColour());
//	}
//}
//
