#pragma once
#include "Character.h"
class Enemy : public Character
{
public:
	Enemy(const char* texture, int x, int y, int characterSpeed, int id);
	virtual ~Enemy();

	virtual void Update(std::vector<std::vector<int> >& map);
	virtual void Render();
	///simple enemy movement, randomly decides direction and then tries to move
	void randomMove(std::vector<std::vector<int> >& map);
	virtual std::pair<int, int> getPosition();
private:
	///time since last movement
	Uint32 lastMove;
};

