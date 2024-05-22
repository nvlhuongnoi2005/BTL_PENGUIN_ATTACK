#include "Colission.h"

void Colission::Render(SDL_Renderer* ren)
{
	SDL_Rect src, dest;
	src = getSrc();
	dest = getDest();
	if (animationTimer != -1)
	{
		animationTimer++;
		if (animationTimer < 16)
		{
			SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer >= 16 && animationTimer <= 32)
		{
			SDL_RenderCopyEx(ren, Tex1, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 32 && animationTimer <=48)
		{
			SDL_RenderCopyEx(ren, Tex2, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 48 && animationTimer <= 64)
		{
			SDL_RenderCopyEx(ren, Tex3, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 64  && animationTimer <= 80)
		{
			SDL_RenderCopyEx(ren, Tex4, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 80 && animationTimer <= 96)
		{
			SDL_RenderCopyEx(ren, Tex5, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 96 && animationTimer <= 112)
		{
			SDL_RenderCopyEx(ren, Tex6, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 112 && animationTimer <= 128)
		{
			SDL_RenderCopyEx(ren, Tex7, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 128 && animationTimer <= 144)
		{
			SDL_RenderCopyEx(ren, Tex8, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 144 && animationTimer <= 160)
		{
			SDL_RenderCopyEx(ren, Tex9, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 160 && animationTimer <= 176)
		{
			SDL_RenderCopyEx(ren, Tex10, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else if (animationTimer > 176 && animationTimer <= 192)
		{
			SDL_RenderCopyEx(ren, Tex11, &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		if (animationTimer >=192)
		{
			animationTimer = 0;
		}
	}
	else
	{
		SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_HORIZONTAL);
		setDest(dest.x, dest.y, dest.w, dest.h);
	}
}
void Colission::Update()
{
	if (animationTimer != -1)
	{
		Time++;
		if (Time % 500 == 0) { acc += 0.5; }
		xPos -= 1.5 + acc;
		setSrc(0, 0, 110, 138);
		setDest(xPos, 480, 110, 138);
		if (xPos < -100) 
		{
			Score++;
			SDL_DestroyTexture(getTexture());
			SDL_DestroyTexture(Tex1);
			SDL_DestroyTexture(Tex2);
			SDL_DestroyTexture(Tex3);
			SDL_DestroyTexture(Tex4);
			SDL_DestroyTexture(Tex5);
			SDL_DestroyTexture(Tex6);
			SDL_DestroyTexture(Tex7);
			SDL_DestroyTexture(Tex8);
			SDL_DestroyTexture(Tex9);
			SDL_DestroyTexture(Tex10);
			SDL_DestroyTexture(Tex11);
			xPos = 1100;
		}
	}
}
int Colission::GetScore()
{
	return Score;
}
void Colission::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Colission::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture3(const char* address, SDL_Renderer* ren)
{
	Tex3 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture4(const char* address, SDL_Renderer* ren)
{
	Tex4 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture5(const char* address, SDL_Renderer* ren)
{
	Tex5 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture6(const char* address, SDL_Renderer* ren)
{
	Tex6 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture7(const char* address, SDL_Renderer* ren)
{
	Tex7 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture8(const char* address, SDL_Renderer* ren)
{
	Tex8 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture9(const char* address, SDL_Renderer* ren)
{
	Tex9 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture10(const char* address, SDL_Renderer* ren)
{
	Tex10 = TextureManager::Texture(address, ren);
}
void Colission::CreateTexture11(const char* address, SDL_Renderer* ren)
{
	Tex11 = TextureManager::Texture(address, ren);
}
void Colission::Clear()
{
	SDL_DestroyTexture(getTexture());
	SDL_DestroyTexture(Tex1);
	SDL_DestroyTexture(Tex2);
	SDL_DestroyTexture(Tex3);
	SDL_DestroyTexture(Tex4);
	SDL_DestroyTexture(Tex5);
	SDL_DestroyTexture(Tex6);
	SDL_DestroyTexture(Tex7);
	SDL_DestroyTexture(Tex8);
	SDL_DestroyTexture(Tex9);
	SDL_DestroyTexture(Tex10);
	SDL_DestroyTexture(Tex11);
}
void Colission::Stop()
{
	animationTimer = -1;

}