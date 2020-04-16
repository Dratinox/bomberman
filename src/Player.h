#pragma once
#include "Character.h"
class Player : public Character
{
public:
	Player(const char* texture, int x, int y, int characterSpeed, int id);
	virtual ~Player();

	///places bomb on the map
	void placeBomb();
	///increments the range of player's future bombs
	void plusRange(int range);
	///increments the count of player's bombs
	void plusCount(int count);
	///increments the player's speed
	void plusSpeed();
	///increased player's score
	void addScore(int plusScore);
	///gets players score
	int getScore();
	virtual std::pair<int, int> getPosition();
	virtual void Update(std::vector<std::vector<int> >& map);
	virtual void Render();
private:
	int bombRange;
	int bombCount;
	int score = 0;

	///holds the player's bombs
	std::vector<Bomb*> bombs;
};

