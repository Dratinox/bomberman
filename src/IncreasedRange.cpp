#include "IncreasedRange.h"

IncreasedRange::IncreasedRange(int xpos, int ypos) 
	: PowerUps(xpos, ypos) 
{
}

IncreasedRange::~IncreasedRange() {

}

void IncreasedRange::Activate(Player &player) {
	player.plusRange(1);
}