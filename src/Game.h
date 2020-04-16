#pragma once
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"
#include <map>
#include <iostream>



class Game {
public:
	Game();
	~Game();
	///Initializes the whole game object, creates a window, renderer, sets up gameObjects and creates a map
	void initialize(const char* name, int xpos, int ypos, int width, int height, bool fullscreen, bool multiplayer);

	///returns if the game is active or not, user for main game loop
	bool active() {
		return gameActive;
	}
	static bool gameActive;

	///handles game's events and inputs, calls input manager
	void handleEvents();

	/// updates the state of gameObjects
	void update();
	void render();
	///cleans up all game objects
	void clean();
	/// calls map's generate powerups method
	static void generatePowerups();
	/// upgrades player's score
	static void upgradeScore(int plusScore);
	///activated player's powerup
	static void activatePowerup(int y, int x, int playerId);
	///controls the placement of the bombs on map
	static void bombPlacement(int y, int x, bool place);
	static SDL_Renderer* renderer;
	///if current score > highscore, save new highscore to text file
	static void saveScore();
	///after bomb detonation, check if anyone is affected by the explosion
	static void checkExplosion();

	///returns player1 win status
	bool getWinner();

private:
	int cnt = 0;
	SDL_Window* window;
	std::map<int,bool> keys;
	std::map<int, bool> oldKeys;
};
