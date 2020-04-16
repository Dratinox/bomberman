#include "Map.h"
#include "TextureManager.h"
#include "IncreasedRange.h"
#include "IncreasedCount.h"
#include "Skate.h"
#include <fstream>
#include <string>
#include <time.h>

 
Map::Map() {
	grass = TextureManager::LoadTexture("assets/grass.png");
	gameWall = TextureManager::LoadTexture("assets/gameWall.png");
	borderWall = TextureManager::LoadTexture("assets/borderWall.png");
	destructible = TextureManager::LoadTexture("assets/destructible.png");
	explosion = TextureManager::LoadTexture("assets/explosion.png");
	explodedBlock = TextureManager::LoadTexture("assets/explosion.png");
	increasedRange = TextureManager::LoadTexture("assets/increasedRange.png");
	increasedCount = TextureManager::LoadTexture("assets/increasedCount.png");
	skate = TextureManager::LoadTexture("assets/skate.png");

	if (LoadMap() == false) {
		Game::gameActive = false;
	}
	else {
		generateBlocks();

		src.x = src.y = 0;
		src.w = dest.w = 32;
		src.h = dest.h = 32;

		dest.x = dest.y = 0;
	}
}

Map::~Map() {
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(gameWall);
	SDL_DestroyTexture(borderWall);
	SDL_DestroyTexture(destructible);
	SDL_DestroyTexture(explosion);
	SDL_DestroyTexture(explodedBlock);
	SDL_DestroyTexture(increasedRange);
	SDL_DestroyTexture(increasedCount);
	SDL_DestroyTexture(skate);
	powerUps.clear();
	gameMap.clear();
}

bool Map::random() {
	if (rand() % 2 == 0)
		return true;
	else 
		return false;
}

void Map::generateBlocks() {
	srand(time(NULL));
	for (size_t row = 2; row < gameMap.size(); row++) {
		for (size_t column = 1; column < gameMap[row].size(); column++) {
			if (random()) {
				if (gameMap[row][column] == 2) {
					gameMap[row][column] = 3;
				}
			}
		}
	}
	gameMap[2][1] = 2;
	gameMap[2][2] = 2;
	gameMap[2][3] = 2;
	gameMap[3][1] = 2;
	gameMap[4][1] = 2;
	
	gameMap[18][23] = 2;
	gameMap[18][22] = 2;
	gameMap[18][21] = 2;
	gameMap[17][23] = 2;
	gameMap[16][23] = 2;
}

void Map::DrawMap() {
	int type = 0;

	for (size_t row = 0; row < gameMap.size(); row++) {
		for (size_t column = 0; column < gameMap[row].size(); column++) {
			type = gameMap[row][column];
			dest.x = column * 32;
			dest.y = row * 32;

			switch (type) {
			case 0:
				TextureManager::Draw(borderWall, src, dest);
				break;
			case 1:
				TextureManager::Draw(gameWall, src, dest);
				break;
			case 2:
				TextureManager::Draw(grass, src, dest);
				break;
			case 3:
				TextureManager::Draw(destructible, src, dest);
				break;
			case 4:
				TextureManager::Draw(explodedBlock, src, dest);
				break;
			case 5:
				TextureManager::Draw(explosion, src, dest);
				break;
			case 6:
				TextureManager::Draw(increasedRange, src, dest);
				break;
			case 7:
				TextureManager::Draw(increasedCount, src, dest);
				break;
			case 8:
				TextureManager::Draw(grass, src, dest);
				break;
			case 9:
				TextureManager::Draw(skate, src, dest);
				break;
			default:
				break;
			}
		}
	}
}



bool Map::LoadMap() {
	char tile;
	std::fstream mapFile;
	mapFile.open("assets/map1.txt");
	mapFile>>height;
	mapFile >> width;
	if (height != 20 || width != 25) {
		std::cout << "Spatne rozmery mapy" << std::endl;
		mapFile.close();
		return false;
	}
		gameMap.resize(height);
		for (int row = 0; row < height; row++) {
			for (int column = 0; column < width; column++) {
				mapFile >> tile;
				int block = atoi(&tile);
				if (block > 2 || block < 0) {
					mapFile.close();
					return false;
				}
				gameMap[row].push_back(block);
				mapFile.ignore();
			}
			std::cout << std::endl;
		}
	mapFile.close();
	return true;
}

void Map::generatePowerups() {
	for (size_t row = 0; row < gameMap.size(); row++) {
		for (size_t column = 0; column < gameMap[row].size(); column++) {
			if (gameMap[row][column] == 4) {
				int randomDecision = rand() % 9;
				if (randomDecision == 1 || randomDecision == 3) {
					powerUps[std::make_pair(row, column)] = new IncreasedRange(column * 32, row * 32);
					gameMap[row][column] = 6;
				}
				else if (randomDecision == 2) {
					powerUps[std::make_pair(row, column)] = new IncreasedCount(column * 32, row * 32);
					gameMap[row][column] = 7;
				}
				else if (randomDecision == 4) {
					powerUps[std::make_pair(row, column)] = new Skate(column * 32, row * 32);
					gameMap[row][column] = 9;
				}
				else
					gameMap[row][column] = 2;
			}
			else if (gameMap[row][column] == 5)
				gameMap[row][column] = 2;
		}
	}
}

void Map::activatePowerup(int y, int x, Player &player) {
	powerUps[std::make_pair(y, x)]->Activate(player);
	powerUps.erase(std::make_pair(y, x));
	gameMap[y][x] = 2;
}

void Map::endGame() {
	SDL_Delay(2000);
	Game::gameActive = false;
}
