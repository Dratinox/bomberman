#pragma once
#define SDL_MAIN_HANDLER
#include "SDL2/SDL.h"
#include "Bomb.h"
#include <vector>

class Character {
public:
	Character (const char* texture, int x, int y, int characterSpeed, int id);
	virtual ~Character();

	///updates character's position and SDL_rectangles
	virtual void Update(std::vector<std::vector<int> >& map);
	///Renders character's texture on the screen
	virtual void Render();
	///controls character movement, always checks for collision when the character moves, if its not successfull, character stays still
	void Move(int direction, std::vector<std::vector<int> >& map);
	///return characters movement state -- used for smooth character sliding
	int getMoveState();
	/// returns characters position
	virtual std::pair<int, int> getPosition();
	///checks for collision in the direction that the character is moving in
	bool checkCollision(int direction, std::vector<std::vector<int> >& map);
	bool win;
protected:
	int xpos;
	int ypos;
	int speed;
	int playerId;
	

	int moveState;

	SDL_Texture* characterTexture;
	SDL_Rect srcRect, destRect;

	


};
