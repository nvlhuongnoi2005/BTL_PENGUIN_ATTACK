#pragma once
#include "Object.h"
class Ground :public Object
{
private:
	bool stop = 0;
public:
	void Render(SDL_Renderer* ren);
	void Update();
	void Stop();
};

