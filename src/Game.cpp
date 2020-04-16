#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "Map.h"
#include "Bomb.h"
#include "Enemy.h"
#include <fstream>

Player* player = nullptr;
Player* player2 = nullptr;
Enemy* enemy = nullptr;
SDL_Renderer* Game::renderer = nullptr;
Map* map = nullptr;
bool Game::gameActive = false;

Game::Game() {
}

Game::~Game() {

}

void Game::initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen, bool multiplayer) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		int full = 0;
		if (fullscreen)
			full = SDL_WINDOW_FULLSCREEN;

		std::cout << "Initialized" << std::endl;

		window = SDL_CreateWindow(name, xpos, ypos, width, height, full);

		if (window) {
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		gameActive = true;

	}
	else {
		std::cout << "Error : " << SDL_GetError() << std::endl;
		gameActive = false;
	}

	player = new Player("assets/characterRight.png", 32, 64, 2, 1);
	if (multiplayer)
		player2 = new Player("assets/bomberman.png", 736, 576, 2, 2);
	else
		enemy = new Enemy("assets/enemy.png", 736, 576, 32, 0);
	map = new Map();
}

void Game::handleEvents() {
	
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		gameActive = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym < 323) {
				//if (oldKeys[event.key.keysym.sym] == false) {
					//oldKeys[event.key.keysym.sym] = true;
					keys[event.key.keysym.sym] = true;
				//}		
		}
		break;
	case SDL_KEYUP:
		if (event.key.keysym.sym < 323) {
			//if (oldKeys[event.key.keysym.sym] == true) {
				//oldKeys[event.key.keysym.sym] = false;
				keys[event.key.keysym.sym] = false;
			//}
			break;
		}
	default:
		break;
	}
	
}

void Game::update() {
	if (player2 != nullptr) {
		InputHandler::handleInputTwo(keys, *player, *player2, map->gameMap);
	}
	else {
		InputHandler::handleInput(keys,*player, map->gameMap);
	}
	/*if (keys[SDLK_SPACE]) {
		player->PutBomb();
	}*/
	player->Update(map->gameMap);
	if (player2 != nullptr)
		player2->Update(map->gameMap);
	if (enemy != nullptr)
		enemy->Update(map->gameMap);
}

void Game::render() {
	SDL_RenderClear(renderer);
	map->DrawMap();
	if (player2 != nullptr)
		player2->Render();
	player->Render();
	if (enemy != nullptr)
		enemy->Render();
	SDL_RenderPresent(renderer);

}

void Game::clean() {
	delete player;
	if (player2 != nullptr) {
		delete player2;
	}
	else {
		delete enemy;
	}
	delete map;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	

}

void Game::generatePowerups() {
	map->generatePowerups();
}

void Game::activatePowerup(int y, int x, int playerId) {
	if (playerId == 1)
		map->activatePowerup(y,x,*player);
	else if (playerId == 2)
		map->activatePowerup(y,x,*player2);
}

void Game::bombPlacement(int y, int x, bool place) {
	int row = y / 32;
	int column = x / 32;
	if (place)
		map->gameMap[row][column] = 8;
	else
		map->gameMap[row][column] = 2;
}

void Game::upgradeScore(int plusScore) {
	if (player2 == nullptr)
		player->addScore(plusScore);
}

void Game::saveScore() {
	int highscore = 0;
	std::fstream scoreFile;
	scoreFile.open("assets/score.txt");
	scoreFile >> highscore;
	scoreFile.close();
	if (player->getScore() > highscore) {
		std::ofstream scoreOutput;
		scoreOutput.open("assets/score.txt");
		scoreOutput << player->getScore();
		scoreOutput.close();
	}

}

void Game::checkExplosion() {
	int x = 0;
	int y = 0;
	std::pair<int, int> position;
	
	int x2 = 0;
	int y2 = 0;
	std::pair<int, int> position2;

	position2 = player->getPosition();
	y2 = position2.first / 32;
	x2 = position2.second / 32;

	
	if (player2 != nullptr) {
		position = player2->getPosition();
		y = position.first / 32;
		x = position.second / 32;
	}
	else {
		position = enemy->getPosition();
		y = position.first / 32;
		x = position.second / 32;
	}

	if (map->gameMap[y][x] == 4 || map->gameMap[y][x] == 5) {
		player->win = true;
		Map::endGame();
	}
		
	else if (map->gameMap[y2][x2] == 4 || map->gameMap[y2][x2] == 5) {
		player->win = false;
		Map::endGame();
	}

}

bool Game::getWinner() {
	return player->win;
}
