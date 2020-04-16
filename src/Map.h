#pragma once
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "PowerUps.h"
#include "Character.h"
#include <map>

class Map {
public:
	Map();
	~Map();
	
	/// loads the map from txtfile, returns false if map is of bad type
	bool LoadMap();
	/// draws map on the screen
	void DrawMap();
	/// randomly generates destructinle blocks
	void generateBlocks();
	///after destroying a block, generates powerups
	void generatePowerups();
	/// spits out random value
	bool random();
	/// activates powerup for a player
	void activatePowerup(int y, int x, Player &player);
	/// ends the game
	static void endGame();
	

	int height;
	int width;

	SDL_Rect src, dest;
	SDL_Texture* grass;
	SDL_Texture* gameWall;
	SDL_Texture* borderWall;
	SDL_Texture* destructible;
	SDL_Texture* explosion;
	SDL_Texture* explodedBlock;
	SDL_Texture* increasedRange;
	SDL_Texture* increasedCount;
	SDL_Texture* skate;
	
	std::map<std::pair<int,int>, PowerUps * > powerUps;
	
	std::vector<std::vector<int> > gameMap;

};
