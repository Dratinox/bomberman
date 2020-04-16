#pragma once
#include "Player.h"
#include <map>

class InputHandler {
public:
	/// handles keyboard input for singleplayer 
	static void handleInput(std::map<int, bool>& keys, Player &player, std::vector<std::vector<int> >& map);
	///handles keyboard input for multiplayer
	static void handleInputTwo(std::map<int, bool>& keys, Player& player, Player& player2, std::vector<std::vector<int> >& map);
};
