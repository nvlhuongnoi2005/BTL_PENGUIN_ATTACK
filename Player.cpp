#include "Player.h"
#include <iostream>
void Player::Render(SDL_Renderer* ren)
{
	src = getSrc();
	dest = getDest();
	animationTimer++;
	if (Alive == true)
	{
		if (animationTimer < 16)
		{
			SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer >= 16 && animationTimer <= 32)
		{
			SDL_RenderCopyEx(ren, Tex1, &src, &dest, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer > 32)
		{
			SDL_RenderCopyEx(ren, Tex2, &src, &dest, 0, NULL, SDL_FLIP_NONE);
		}
		else if (animationTimer >= 48 && animationTimer <= 64)
		{
			SDL_RenderCopyEx(ren, Tex3, &src, &dest, 0, NULL, SDL_FLIP_NONE);
		}
		if (animationTimer > 64)
		{
			animationTimer = 0;
		}
	}
	else
	{
			SDL_RenderCopyEx(ren, getTexture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
			SDL_DestroyTexture(Tex1);
			SDL_DestroyTexture(Tex2);
			SDL_DestroyTexture(Tex3);
	}
}

void Player::Gravity()
{
	if (Alive == true)
	{
		if (JumpState())
		{
			jumpHeight = jumpHeight + gravity;
			Ypos -= 5;
			Xpos += 1;
			setDest(Xpos, Ypos, 72, 64);
			if (jumpHeight > 0)
			{
				inJump = false;
				jumpHeight = -6;
			}
		}
		else
		{

			Ypos += 4;
			if (Ypos > 532) Ypos = 532;
			if (Ypos == 532 && Xpos != 200) Xpos -= 0.5;
			setDest(Xpos, Ypos, 72, 64);
		}
	}

}
void Player::Jump()
{
	if (jumpTimer - lastJump > 200)
	{
		inJump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}
void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();
}

bool Player::JumpState()
{
	return inJump;
}
void Player::CreateTexture1(const char* address, SDL_Renderer* ren)
{
	Tex1 = TextureManager::Texture(address, ren);
}

void Player::CreateTexture2(const char* address, SDL_Renderer* ren)
{
	Tex2 = TextureManager::Texture(address, ren);
}
void Player::CreateTexture3(const char* address, SDL_Renderer* ren)
{
	Tex3 = TextureManager::Texture(address, ren);
}
void Player::Clear()
{
	SDL_DestroyTexture(getTexture());
	SDL_DestroyTexture(Tex1);
	SDL_DestroyTexture(Tex2);
	SDL_DestroyTexture(Tex3);
}
void Player::EndGame()
{
	Alive = false;
}