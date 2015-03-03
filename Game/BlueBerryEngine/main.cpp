#include "Game.h"
//#include "TestGame.h"

// Entry point for the game
int main()
{
	// Create an instance of the game
	Game *pGame = new Game("Basic Demo", 800,600);

	//start it
	pGame->Run();

	return 0;
}

// End of main.cpp