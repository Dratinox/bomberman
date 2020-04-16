#pragma once
#include "PowerUps.h"

class IncreasedRange : public PowerUps
{
public:
	IncreasedRange(int xpos, int ypos);
	~IncreasedRange();
	virtual void Activate(Player &player);
};

