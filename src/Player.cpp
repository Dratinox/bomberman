#include "Player.h"
#include "Game.h"
#include "Map.h"

Player::Player(const char* texture, int x, int y, int characterSpeed, int id)
	: Character(texture, x, y, characterSpeed, id)
{
	bombRange = 1;
	bombCount = 1;
	
}

Player::~Player() {
	bombs.clear();
}

void Player::placeBomb() {
	if ((int)bombs.size() < bombCount) {
		Bomb* bomb = new Bomb("assets/bomb.png", "assets/explosion.png", xpos, ypos, bombRange);
		Game::bombPlacement(ypos ,xpos , 1);
		bombs.push_back(bomb);
	}
}

void Player::plusRange(int range) {
	bombRange += range;
}

void Player::plusCount(int count) {
	bombCount += count;
}

void Player::Update(std::vector<std::vector<int> >& map) {
	Character::Update(map);
	for (auto iter = bombs.begin(); iter != bombs.end();) {
		if ((*iter)->Update(map)) {
			Game::checkExplosion();
			iter = bombs.erase(iter);
			Game::generatePowerups();
			Game::bombPlacement(ypos, xpos, 0);
		}
		else
			iter++;
	}
}

void Player::Render() {
	Character::Render();
	for (auto iter = bombs.begin(); iter != bombs.end(); iter++) {
		(*iter)->Render();
	}
}

void Player::plusSpeed() {
	if (speed == 2)
		speed = 4;
	else if (speed == 4)
		speed = 8;
}

void Player::addScore(int plusScore) {
	score += plusScore;
}

int Player::getScore() {
	return score;
}

std::pair<int, int> Player::getPosition() {
	return std::make_pair(ypos, xpos);
}
