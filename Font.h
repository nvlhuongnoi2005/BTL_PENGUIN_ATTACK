#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include<string>
using namespace std;
class Font
{
public:
	TTF_Font* loadFont(const string path, int size);
	SDL_Texture* CreateFont(TTF_Font* font, const string text, SDL_Renderer* ren);
	virtual void Render(SDL_Texture* text, int x, int y, SDL_Renderer* ren);

};

