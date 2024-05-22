#include "GameLoop.h"


GameLoop* game = new GameLoop();
int main(int argc, char* argv[])
{
	bool check = 1;
	srand((int)time(0));
	// Limit Frame Rate
	double frameRate = 1000 / 60;
	double first;
	double last = 0;
	
	while (check)
	{
		game->Clear();
		GameLoop* game = new GameLoop();
		game->Intialize();
		while (!game->GameStart())
		{
			if (!game->Loop()) { return 0; }
			game->EventStart();
			if (game->GetHighScore())
			{
				game->PrintHighScore();
			}
			else if (game->GetInfor())
			{
				game->PrintInfor();
			}
			else game->MenuStart();
		}
		while (game->getGameState())
		{
			game->Event();
			first = SDL_GetTicks();
			if (first - last < frameRate)
			{
				SDL_Delay(frameRate - (first - last));
			}
			last = first;
			if (!game->IsDead())
			{
				game->RenderPlayer();
				game->RenderOpponent();
				game->Update();
				game->Render();

			}
			else
			{
				
				if (game->GetHighScore()) { game->PrintHighScore(); }
				else game->EndGame();
			}
		}
		ifstream input("Best.txt");
		int best_score;
		input >> best_score;
		ofstream output("Best.txt");
		if (game->Score() > best_score)
		{
			output << game->Score();
		}
		else
		{
			output << best_score;
		}
		check = game->Loop();
	}
	game->Clear();
	return 0;
}
