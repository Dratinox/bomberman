#pragma once
#include "PowerUps.h"
class IncreasedCount : public PowerUps
{
public:
	IncreasedCount(int xpos, int ypos);
	~IncreasedCount();
	virtual void Activate(Player& player);
};

