#pragma once
#include "PowerUps.h"
class Skate : public PowerUps
{
public:
	Skate(int xpos, int ypos);
	~Skate();
	virtual void Activate(Player& player);
};

