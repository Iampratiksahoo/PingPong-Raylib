#include <iostream>
#include "Game/Game.h"

int main(void)
{
	Game* game = new Game();
	game->Setup();
	game->Play();
	game->Cleanup();
	return 0;
}