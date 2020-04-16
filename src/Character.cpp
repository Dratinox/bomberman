#include "Character.h"
#include "Map.h"
#include "TextureManager.h"

enum direction { right = 1, up, left, down };

Character::Character(const char* texture, int x, int y, int characterSpeed, int id) {

	characterTexture = TextureManager::LoadTexture(texture);

	xpos = x;
	ypos = y;
	speed = characterSpeed;
	playerId = id;
	destRect = { x, y, 0, 0 };
	srcRect = { 0, 0, 0, 0 };
	moveState = 0;
	win = false;

}

Character::~Character() {
	SDL_DestroyTexture(characterTexture);
}

void Character::Update(std::vector<std::vector<int> > &map) {


	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}

bool Character::checkCollision(int direction, std::vector<std::vector<int> >& map) {

	

	int x = xpos / 32;
	int y = ypos / 32;

	switch (direction) {
	case 1:
		x++;
		break;
	case 2:
		y--;
		break;
	case 3:
		x--;
		break;
	case 4:
		y++;
		break;
	default: 
		break;
	}

	if (x < 1 || y < 2 || x > 24 || y > 19)
		return true;

	if (map[y][x] == 4 || map[y][x] == 5) {

		Map::endGame();
}

	if (map[y][x] == 6 || map[y][x] == 7 || map[y][x] == 9) {
		if (playerId != 0)
			Game::activatePowerup(y, x, playerId);
		return false;
	}

	if (map[y][x] != 2)
		return true;
	
	return false;
}



void Character::Move(int direction, std::vector<std::vector<int> > &map) {

	switch (direction) {
	case right:
		if (xpos % 32 == 0 && !checkCollision(1, map) == 1) {
			moveState = 1;
		}
		if (moveState == 1)
			xpos += speed;
		if (xpos % 32 == 0)
			moveState = 0;
		break;
	case up:
		if (ypos % 32 == 0 && !checkCollision(2, map) == 1) {
			moveState = 2;
		}
		if (moveState == 2)
			ypos -= speed;
		if (ypos % 32 == 0)
			moveState = 0;
		break;
	case left:
		if (xpos % 32 == 0 && !checkCollision(3, map) == 1) {
			moveState = 3;
		}
		if (moveState == 3)
			xpos -= speed;
		if (xpos % 32 == 0)
			moveState = 0;
		break;
	case down:
		if (xpos % 32 == 0 && !checkCollision(4, map) == 1) {
			moveState = 4;
		}
		if (moveState == 4)
			ypos += speed;
		if (ypos % 32 == 0)
			moveState = 0;
		break;
	default: 
		break;
	}
}


void Character::Render() {
	SDL_RenderCopy(Game::renderer, characterTexture, &srcRect, &destRect);
	
}


int Character::getMoveState() {
	return moveState;
}

std::pair<int, int> Character::getPosition() {
	return std::make_pair(ypos, xpos);
}
