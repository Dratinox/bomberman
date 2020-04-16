#pragma once
#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
class Bomb
{
public:
	Bomb(const char *filename, const char *bombName, int x, int y, int bombRange);
	~Bomb();

	///gets bomb's coordinates, calculater range and then explodes into four directions, destroys crates and kills players/enemies
	void Explode(std::vector<std::vector<int> >& map);
	
	void Render();
	bool Update(std::vector<std::vector<int> >& map);
private:
	int xpos;
	int ypos;
	int range;
	Uint32 bombSetTime, bombExplosionTime = 0;
	SDL_Texture* bombTexture;
	SDL_Rect srcRect, destRect;
};

