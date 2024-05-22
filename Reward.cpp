#include "Reward.h"

void Reward::Render(SDL_Renderer* ren)
{
	src = getSrc();
	dest = getDest();
	SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}
void Reward::Update()
{
	if (stop == 0)
	{
		Time++;
		if (Time % 500 == 0) { acc += 0.5; }
		xPos -= 1.5 + acc;
		setDest(xPos, 530, 80, 80);
		if (xPos < -100)
		{
			xPos = 1100;
			SDL_DestroyTexture(getTexture());
		}
	}
	else
	{
		xPos = 1100;
		SDL_DestroyTexture(getTexture());
		stop = 0;
	}
	
}
void Reward::Score()
{
	score += 2;
	stop = 1;
}
int Reward::GetScore()
{
	return score;
}
void Reward::Clear()
{
	SDL_DestroyTexture(getTexture());
}