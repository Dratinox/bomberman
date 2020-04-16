#include "Bomb.h"
#include "Game.h"

Bomb::Bomb(const char *filename, const char *bombName, int x, int y, int bombRange) {
	bombTexture = TextureManager::LoadTexture(filename);
	xpos = x;
	ypos = y;
	range = bombRange;
	bombSetTime = SDL_GetTicks();

	
}

Bomb::~Bomb() {
	SDL_DestroyTexture(bombTexture);
}

void Bomb::Explode(std::vector<std::vector<int> >& map) {
	bombExplosionTime = SDL_GetTicks();
	int x = xpos / 32;
	int y = ypos / 32;
	///if the coordinates are not out of map boundaries -> looks in all four directions and explodes accordingly
	if (!(x > 24 || x < 0) && !(y < 0 || y > 19)) {
		
		for (int i = x; i <= x + range; i++) {
			if (i > 24)
				break;
			if (map[y][i] == 1 || map[y][i] == 0)
				break;
			else if (map[y][i] == 3) {
				Game::upgradeScore(50);
				map[y][i] = 4;
				break;
			}
			else if (map[y][i] == 2 || map[y][i] == 2) {
				map[y][i] = 5;
			}
		}

		for (int i = x; i >= x - range; i--) {
			if (i < 1)
				break;
			if (map[y][i] == 1 || map[y][i] == 0)
				break;
			else if (map[y][i] == 3) {
				Game::upgradeScore(50);
				map[y][i] = 4;
				break;
			}
			else if (map[y][i] == 2 || map[y][i] == 8) {
				map[y][i] = 5;
			}
		}

		for (int i = y; i <= y + range; i++) {
			if (i > 19)
				break;
			if (map[i][x] == 1 || map[i][x] == 0)
				break;
			else if (map[i][x] == 3) {
				Game::upgradeScore(50);
				map[i][x] = 4;
				break;
			}
			else if (map[i][x] == 2 || map[i][x] == 8) {
				map[i][x] = 5;
			}
		}

		for (int i = y; i >= y - range; i--) {
			if (i < 1)
				continue;
			if (map[i][x] == 1 || map[i][x] == 0)
				break;
			else if (map[i][x] == 3) {
				Game::upgradeScore(50);
				map[i][x] = 4;
				break;
			}
			else if (map[i][x] == 2 || map[i][x] == 8) {
				map[i][x] = 5;
			}
		}
	}
}

bool Bomb::Update(std::vector<std::vector<int> >& map) {
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	///if enough time passed, handle the bomb accordingly
	if (SDL_GetTicks() > bombSetTime + 2000) {
		if (bombExplosionTime == 0)
			Explode(map);
		if (SDL_GetTicks() > bombExplosionTime + 1000)
			return true;
	}
	return false;
}

void Bomb::Render() {
	if (bombExplosionTime == 0)
		SDL_RenderCopy(Game::renderer, bombTexture, &srcRect, &destRect);
}
