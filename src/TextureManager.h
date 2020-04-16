#pragma once

#include "Game.h"

class TextureManager {
public:
	/// loads image into surface, puts into texture and returns
	static SDL_Texture* LoadTexture(const char* filename);
	///draws texture on the map through renderer
	static void Draw(SDL_Texture * texture, SDL_Rect src, SDL_Rect dest);
};
