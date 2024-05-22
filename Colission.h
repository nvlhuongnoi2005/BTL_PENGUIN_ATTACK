#pragma once
#include "Object.h"
class Colission : public Object
{
private:
	SDL_Texture* Tex1;
	SDL_Texture* Tex2;
	SDL_Texture* Tex3;
	SDL_Texture* Tex4;
	SDL_Texture* Tex5;
	SDL_Texture* Tex6;
	SDL_Texture* Tex7;
	SDL_Texture* Tex8;
	SDL_Texture* Tex9;
	SDL_Texture* Tex10;
	SDL_Texture* Tex11;
	int animationTimer;
	double xPos = 1100;
	int Time=0;
	double acc=1.5;
	int Score = 0;
public:
	void Update();
	void CreateTexture1(const char* address, SDL_Renderer* ren);
	void CreateTexture2(const char* address, SDL_Renderer* ren);
	void CreateTexture3(const char* address, SDL_Renderer* ren);
	void CreateTexture4(const char* address, SDL_Renderer* ren);
	void CreateTexture5(const char* address, SDL_Renderer* ren);
	void CreateTexture6(const char* address, SDL_Renderer* ren);
	void CreateTexture7(const char* address, SDL_Renderer* ren);
	void CreateTexture8(const char* address, SDL_Renderer* ren);
	void CreateTexture9(const char* address, SDL_Renderer* ren);
	void CreateTexture10(const char* address, SDL_Renderer* ren);
	void CreateTexture11(const char* address, SDL_Renderer* ren);
	void Clear();
	void Render(SDL_Renderer* ren);
	void Stop();
	int GetScore();
};

