#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "Game.h"
using namespace std;

Game* game = nullptr;


int main(int argc, char* argv[])
{	
	SDL_SetMainReady();

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	int gameMode = 2;
	while (gameMode != 0 && gameMode != 1) {
		cout << "Select game mode: 0 - singleplayer, 1 - multiplayer" << endl;
		cin >> gameMode;
	}
	

	game = new Game();

	game->initialize("BomberMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false, gameMode);

	while (game->active()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->saveScore();
	if (game->getWinner())
		std::cout << "Player 1 won the game." << std::endl;
	else 
		std::cout << "Player 1 lost the game." << std::endl;
	
	game->clean();
	delete game;
	return 0;
}
