#pragma once

#include "TextureManager.h"
class Object
{
private:
	SDL_Texture* Tex;
public:
	SDL_Rect src, dest;
	Object();
	SDL_Rect getSrc();
	SDL_Rect getDest();
	void setSrc(double x, double y, double w, double h);
	void setDest(double x, double y, double w, double h);
	SDL_Texture* getTexture();
	

	void CreateTexture(const char* address, SDL_Renderer* ren);
	void virtual Render(SDL_Renderer* ren) = 0;
};