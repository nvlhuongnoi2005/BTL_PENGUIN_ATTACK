#pragma once
#include "Object.h"
class Reward : public Object
{
private:
	bool stop = 0;
	double xPos = 1100;
	int Time = 0;
	double acc = 1.5;
	int score;
public:
	void Update();
	void Render(SDL_Renderer* ren);
	void Clear();
	void Score();
	int GetScore();
};

