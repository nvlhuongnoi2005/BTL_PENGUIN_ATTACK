#pragma once
#include "Object.h"
class Background :public Object
{
private:
	double xPos=0;
public:
	void Render(SDL_Renderer* ren);
	void Ground(SDL_Renderer* ren);
	void Update();
};

