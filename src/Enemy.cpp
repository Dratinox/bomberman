#include "Enemy.h"
#include <time.h>
#include <vector>

Enemy::Enemy(const char* texture, int x, int y, int characterSpeed, int id)
	: Character(texture, x, y, characterSpeed, id)
{
	lastMove = SDL_GetTicks();

}

Enemy::~Enemy() {
}

void Enemy::randomMove(std::vector<std::vector<int> > &map) {
	int oldx = xpos;
	int oldy = ypos;
	srand((int)time(NULL));
	if (SDL_GetTicks() > lastMove + 500) {

		int randomDecision = rand() % 5;
		if (randomDecision != 0) {
			Character::Move(randomDecision, map);
		}
		if (xpos != oldx || ypos != oldy)
			lastMove = SDL_GetTicks();
	}
}

void Enemy::Update(std::vector<std::vector<int> >& map) {
	Character::Update(map);
	randomMove(map);
}

void Enemy::Render() {
	Character::Render();
}

std::pair<int, int> Enemy::getPosition() {
	return std::make_pair(ypos, xpos);
}
