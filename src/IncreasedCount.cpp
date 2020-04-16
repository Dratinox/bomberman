#include "IncreasedCount.h"

IncreasedCount::IncreasedCount(int xpos, int ypos)
	: PowerUps(xpos, ypos)
{
}

IncreasedCount::~IncreasedCount() {

}

void IncreasedCount::Activate(Player& player) {
	player.plusCount(1);
}