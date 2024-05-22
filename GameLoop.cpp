#include "GameLoop.h"
GameLoop::GameLoop()
{
	window = NULL;
	renderer = NULL;
	GameState = false;
	g.setSrc(0, 0, 2400,720);
	g.setDest(0, 0, 2400,720);
	p.setSrc(0, 0, 72, 64);
	p.setDest(150, 532 , 72, 64);
	c.setSrc(0, 0, 110, 138);
	c.setDest(1100, 480, 110, 138);
	r.setSrc(0, 0, 80, 80);
	r.setDest(1100, 550, 80, 80);
	Start = 0;
	HighScore = 0;
	Infor = 0;
	SDL_Init(SDL_INIT_EVERYTHING);
	if (TTF_Init() == -1)
	{
		cerr << 0;
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	sound = Mix_LoadWAV("sound/jump.mp3");
	music = Mix_LoadMUS("sound/music.mp3");
	
}
int GameLoop::Random(int Min, int Max)
{
	return Min + rand() % (Max - Min + 1);
}
bool GameLoop::getGameState()
{
	return GameState;
}
bool GameLoop::GameStart()
{
	return Start;
}
void GameLoop::Intialize()
{
	
	Mix_PlayMusic(music, -1);
	window = SDL_CreateWindow("Penguin Attack!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	if (window)
	{
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			cerr << "Succeeded!" << endl;
		}
		else
		{
			cerr << "Not created!" << endl;
		}
	}
	else
	{
		cerr << "window not created!" << endl;
	}
}
void GameLoop::Clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}
void GameLoop::MenuStart()
{
	SDL_RenderClear(renderer);

	// Back Menu
	SDL_Texture* MenuS = TextureManager::Texture("images/MenuStart.png", renderer);
	SDL_RenderCopy(renderer, MenuS, NULL, NULL);
	SDL_DestroyTexture(MenuS);
	//Button Start
	SDL_Texture* ButtonS = TextureManager::Texture("images/Button/Start.png", renderer);
	SDL_Rect destS = { 474,396,80,80 };
	SDL_RenderCopy(renderer, ButtonS, NULL, &destS);
	SDL_DestroyTexture(ButtonS);
	//Button infor
	SDL_Texture* ButtonI = TextureManager::Texture("images/Button/Infor.png", renderer);
	SDL_Rect destI = { 574,396,80,80 };
	SDL_RenderCopy(renderer, ButtonI, NULL, &destI);
	SDL_DestroyTexture(ButtonI);
	//Button HighScore
	SDL_Texture* ButtonH = TextureManager::Texture("images/Button/HighScore.png", renderer);
	SDL_Rect destH = { 374,396,80,80 };
	SDL_RenderCopy(renderer, ButtonH, NULL, &destH);
	SDL_DestroyTexture(ButtonH);
	SDL_RenderPresent(renderer);
}
void GameLoop::EventStart()
{
	SDL_PollEvent(&EventS);

	if (EventS.type == SDL_QUIT)
	{
		Start = 1;
		GameState = 0;
		checkLoop = 0;
	}

	else if (EventS.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		cerr << x << " " << y << '\n';
		if (x>=376 && x<=448 && y>= 398 && y<=472)
		{
			HighScore = 1;
		}
		else if (x >= 481 && x <= 538 && y >= 396 && y <= 473)
		{
			Start = 1;
			GameState = 1;
			b.CreateTexture("images/BG.png", renderer);
			g.CreateTexture("images/Ground.png", renderer);
		}
		else if (x >= 574 && x <= 653 && y >= 396 && y <= 472)
		{
			Infor = 1;
		}
	}
}
void GameLoop::PrintHighScore()
{
	if (HighScore)
	{
		SDL_RenderClear(renderer);
		SDL_Texture* Print = TextureManager::Texture("images/Scenes/HighScore.png", renderer);
		SDL_RenderCopy(renderer, Print, NULL, NULL);
		SDL_DestroyTexture(Print); Print = nullptr;
		SDL_RenderPresent(renderer);

		SDL_Event EventH;
		SDL_PollEvent(&EventH);

		if (EventH.type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (x >= 15 && x <= 104 && y >= 11 && y <= 98)
			{
				HighScore = 0;
			}
			
		}

	}
}
bool GameLoop::GetHighScore()
{
	return HighScore;
}
void GameLoop::PrintInfor()
{
	if (Infor)
	{
		SDL_RenderClear(renderer);
		SDL_Texture* Print = TextureManager::Texture("images/Scenes/Infor.png", renderer);
		SDL_RenderCopy(renderer, Print, NULL, NULL);
		SDL_DestroyTexture(Print); Print = nullptr;
		SDL_RenderPresent(renderer);

		SDL_Event EventH;
		SDL_PollEvent(&EventH);

		if (EventH.type == SDL_MOUSEBUTTONDOWN)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			if (x >= 15 && x <= 104 && y >= 11 && y <= 98)
			{
				Infor = 0;
			}

		}

	}
}
bool GameLoop::GetInfor()
{
	return Infor;
}
void GameLoop::RenderPlayer()
{
	
	if (Dead != true && Start ==1 )
	{
		if (p.JumpState())
		{
			p.CreateTexture("images/Player/Jump/1.png", renderer);
			p.CreateTexture1("images/Player/Jump/2.png", renderer);
			p.CreateTexture2("images/Player/Jump/3.png", renderer);
			p.CreateTexture3("images/Player/Jump/3.png", renderer);
		}
		else
		{
			p.CreateTexture("images/Player/Walk/1.png", renderer);
			p.CreateTexture1("images/Player/Walk/2.png", renderer);
			p.CreateTexture2("images/Player/Walk/3.png", renderer);
			p.CreateTexture3("images/Player/Walk/4.png", renderer);
		}
	}
	
}
void GameLoop::RenderOpponent()
{
	if (Opponent == 0)
	{
		c.CreateTexture("images/Opponent/Golem/1.png", renderer);
		c.CreateTexture1("images/Opponent/Golem/2.png", renderer);
		c.CreateTexture2("images/Opponent/Golem/3.png", renderer);
		c.CreateTexture3("images/Opponent/Golem/4.png", renderer);
		c.CreateTexture4("images/Opponent/Golem/5.png", renderer);
		c.CreateTexture5("images/Opponent/Golem/6.png", renderer);
		c.CreateTexture6("images/Opponent/Golem/7.png", renderer);
		c.CreateTexture7("images/Opponent/Golem/8.png", renderer);
		c.CreateTexture8("images/Opponent/Golem/9.png", renderer);
		c.CreateTexture9("images/Opponent/Golem/10.png", renderer);
		c.CreateTexture10("images/Opponent/Golem/11.png", renderer);
		c.CreateTexture11("images/Opponent/Golem/12.png", renderer);
	}
	else if(Opponent == 1)
	{
		
		c.CreateTexture("images/Opponent/Wraith/1.png", renderer);
		c.CreateTexture1("images/Opponent/Wraith/2.png", renderer);
		c.CreateTexture2("images/Opponent/Wraith/3.png", renderer);
		c.CreateTexture3("images/Opponent/Wraith/4.png", renderer);
		c.CreateTexture4("images/Opponent/Wraith/5.png", renderer);
		c.CreateTexture5("images/Opponent/Wraith/6.png", renderer);
		c.CreateTexture6("images/Opponent/Wraith/7.png", renderer);
		c.CreateTexture7("images/Opponent/Wraith/8.png", renderer);
		c.CreateTexture8("images/Opponent/Wraith/9.png", renderer);
		c.CreateTexture9("images/Opponent/Wraith/10.png", renderer);
		c.CreateTexture10("images/Opponent/Wraith/11.png", renderer);
		c.CreateTexture11("images/Opponent/Wraith/12.png", renderer);
	}
	else
	{
		r.CreateTexture("images/Reward.png", renderer);
	}
}
void GameLoop::Event()
{
	
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		GameState = 0;
		checkLoop = 0;
	}
	else if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP)
		{
			
			Mix_PlayChannel(-1, sound, 0);
			p.GetJumpTime();

			if (!p.JumpState())
			{
				p.Jump();
			}
			else
			{
				p.Gravity();
			}
		}
	}
	else if(Dead == false)
	{
		p.Gravity();
	}

}
void GameLoop::Update()
{
	if (Dead == false)
	{
		g.Update();
		if (destC.x < -100 || destR.x <-100) {
			Opponent = Random(0,2);
		}

		destP = p.getDest();

		if (Opponent == 1 || Opponent == 0)
		{
			bool checkC = 0;
			destC = c.getDest();
			c.Update();
			if (destP.y + destP.h >= 516 && destP.y + destP.h <= destC.y + destC.h)
			{
				if ((destC.x >= destP.x && destC.x <= destP.x + destP.w / 2) || (destP.x > destC.x && destP.x < destC.x + destC.w / 2))
				{
					p.EndGame();
					c.Stop();
					g.Stop();
					c.Clear();
					p.Clear();
					Dead = true;
				}
				
			}
			
		}
		else { 

			r.Update();
			destR = r.getDest();
			bool checkR = 0;
			if (destR.x >= destP.x && destR.x <= destP.x + destP.w/2 && destP.y <= 532 && checkR == 0)
			{
				r.Score();
				checkR = 1;
			}
			
		}

		
	}

	
}



void GameLoop::Render()
{
	SDL_RenderClear(renderer);
	b.Render(renderer);
	if (Dead == true)
	{
		p.Clear();
		c.Clear();
	}
	else
	{
        g.Render(renderer);
		p.Render(renderer); 
		if (Opponent == 0 || Opponent == 1)
		{
              c.Render(renderer);
		}
		else
		{
			r.Render(renderer);
		}
	     
	}
	string text = to_string(c.GetScore());
	TTF_Font* font = fo.loadFont("Font/Monogram.otf", 32);
	SDL_Texture* texture = fo.CreateFont(font, text.c_str(), renderer);
	fo.Render(texture, 20, 20, renderer);
	SDL_RenderPresent(renderer);
	p.Clear();
	c.Clear();
	r.Clear();
}
bool GameLoop::IsDead()
{
	return Dead;
}
void GameLoop::EndGame()
{
	SDL_RenderClear(renderer);
	SDL_Texture* Print = TextureManager::Texture("images/Scenes/End.png", renderer);
	SDL_RenderCopy(renderer, Print, NULL, NULL);
	SDL_DestroyTexture(Print); Print = nullptr;
	SDL_RenderPresent(renderer);

	SDL_Event EventH;
	SDL_PollEvent(&EventH);
	if (EventH.type == SDL_QUIT)
	{
		checkLoop = 0;
		GameState = 0;
		
	}
	else if (EventH.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		
		if (x >= 638 && x <= 734 && y >= 413 && y <= 509)
		{
			checkLoop = 1;
			GameState = 0;
		}
		else
		{
			checkLoop = 0;
			if (x >= 329 && x <= 431 && y <= 509 && y >= 408)
			{
				HighScore = 1;
			}
		}

	}
	
}
bool GameLoop::Loop()
{
	return checkLoop;
}
int GameLoop::Score()
{
	return c.GetScore() + r.GetScore();
}