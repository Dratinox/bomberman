#include "InputHandler.h"


void InputHandler::handleInput( std::map<int,bool> &keys, Player& player, std::vector<std::vector<int> >& map) {
	if (keys[SDLK_w] && player.getMoveState() == 0) {
		keys[SDLK_w] = false;
		player.Move(2, map);
	}
	else if (player.getMoveState() == 2) {
		player.Move(2, map);
	}
	if (keys[SDLK_d] && player.getMoveState() == 0) {
		keys[SDLK_d] = false;
		player.Move(1, map);

	}
	else if (player.getMoveState() == 1) {
		player.Move(1, map);
	}
	if (keys[SDLK_a] && player.getMoveState() == 0) {
		keys[SDLK_a] = false;
		player.Move(3, map);
	}
	else if (player.getMoveState() == 3) {
		player.Move(3, map);
	}
	if (keys[SDLK_s] && player.getMoveState() == 0) {
		keys[SDLK_s] = false;
		player.Move(4, map);
	}
	else if (player.getMoveState() == 4) {
		player.Move(4, map);
	}
	if (keys[SDLK_SPACE] && player.getMoveState() == 0) {
		keys[SDLK_SPACE] = false;
		player.placeBomb();
	}
}

void InputHandler::handleInputTwo(std::map<int, bool>& keys, Player& player, Player& player2, std::vector<std::vector<int> >& map) {
	if (keys[SDLK_w] && player.getMoveState() == 0) {
		keys[SDLK_w] = false;
		player.Move(2, map);
	}
	else if (player.getMoveState() == 2) {
		player.Move(2, map);
	}
	if (keys[SDLK_d] && player.getMoveState() == 0) {
		keys[SDLK_d] = false;
		player.Move(1, map);

	}
	else if (player.getMoveState() == 1) {
		player.Move(1, map);
	}
	if (keys[SDLK_a] && player.getMoveState() == 0) {
		keys[SDLK_a] = false;
		player.Move(3, map);
	}
	else if (player.getMoveState() == 3) {
		player.Move(3, map);
	}
	if (keys[SDLK_s] && player.getMoveState() == 0) {
		keys[SDLK_s] = false;
		player.Move(4, map);
	}
	else if (player.getMoveState() == 4) {
		player.Move(4, map);
	}
	if (keys[SDLK_SPACE] && player.getMoveState() == 0) {
		keys[SDLK_SPACE] = false;
		player.placeBomb();
	}

	if (keys[SDLK_i] && player2.getMoveState() == 0) {
		keys[SDLK_i] = false;
		player2.Move(2, map);
	}
	else if (player2.getMoveState() == 2) {
		player2.Move(2, map);
	}
	if (keys[SDLK_l] && player2.getMoveState() == 0) {
		keys[SDLK_l] = false;
		player2.Move(1, map);
	}
	else if (player2.getMoveState() == 1) {
		player2.Move(1, map);
	}
	if (keys[SDLK_j] && player2.getMoveState() == 0) {
		keys[SDLK_j] = false;
		player2.Move(3, map);
	}
	else if (player2.getMoveState() == 3) {
		player2.Move(3, map);
	}
	if (keys[SDLK_k] && player2.getMoveState() == 0) {
		keys[SDLK_k] = false;
		player2.Move(4, map);
	}
	else if (player2.getMoveState() == 4) {
		player2.Move(4, map);
	}
	if (keys[SDLK_LEFTBRACKET] && player2.getMoveState() == 0) {
		keys[SDLK_LEFTBRACKET] = false;
		player2.placeBomb();
	}
}
