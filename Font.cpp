#include "Font.h"

TTF_Font* Font::loadFont(const string path, int size)
{
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	return font;
}
SDL_Texture* Font::CreateFont(TTF_Font* font, const string text, SDL_Renderer* ren)
{
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {255,255,255});
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(ren, surface);
	SDL_FreeSurface(surface);
	return text_texture;
}
void Font::Render(SDL_Texture* texture, int x, int y, SDL_Renderer* ren)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(ren, texture, NULL, &dest);
}