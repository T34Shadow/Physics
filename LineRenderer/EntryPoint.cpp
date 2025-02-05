#include "ApplicationHarness.h"

//Include the necessary header file here for your game type
#include "PhysicsEnvro.h"
#include "Example.h"
#include "DotClicker.h"

int main()
{
	ApplicationHarness program(new PhysicsEnvro());	//Create a new instance of your application type to pass into the harness here.

	program.Run();

	return 0;
}