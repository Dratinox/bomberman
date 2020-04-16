#include "Skate.h"

Skate::Skate(int xpos, int ypos)
	: PowerUps(xpos, ypos)
{
}

Skate::~Skate() {

}

void Skate::Activate(Player &player) {
	player.plusSpeed();
}