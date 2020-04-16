#pragma once
#include "Player.h"

class PowerUps
{
public:
	PowerUps(int xpos, int ypos);
	~PowerUps();
	///activates the given powerup for a player that picket it up
	virtual void Activate(Player &player) = 0;
protected:
	int xpos;
	int ypos;
};


