#include "Ground.h"

void Ground::Render(SDL_Renderer* ren)
{
	
	src = getSrc();
	dest = getDest();
	SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
	
}
void Ground::Update()
{

   	SDL_Rect dest;
	if (stop != 1)
	{
		dest = getDest();
		dest.x-=2;
		if (dest.x < -1200) dest.x = 5;
		setDest(dest.x, dest.y, dest.w, dest.h);
	}
}
void Ground::Stop()
{
	stop = 1;
	SDL_DestroyTexture(getTexture());
}