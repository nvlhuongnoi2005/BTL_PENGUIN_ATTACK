#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "Object.h"
#include "Player.h"
#include "Background.h"
#include "Colission.h"
#include "Ground.h"
#include "Reward.h"
#include "Font.h"
using namespace std;

class GameLoop
{
private:
    Font fo;
    SDL_Texture* Text;
    Player p;
    Background b;
    Ground g;
    Colission c;
    Reward r;
    const int HEIGHT = 720;
    const int WIDTH = 1080;
    bool GameState;
    SDL_Window* window;
    SDL_Event event;
    SDL_Renderer* renderer;
    SDL_Rect destP, destC, destR;
    int Jumptime = 0;
    bool Dead = false;
    int Opponent;
    long score = 0;
    SDL_Rect dest, src;
    Mix_Music* music;
    Mix_Chunk* sound;
    SDL_Event EventS;
    bool Start;
    bool HighScore;
    bool Infor;
    bool checkLoop=1;

public:
    GameLoop();
    bool GameStart();
    void MenuStart();
    void EventStart();
    void RenderPlayer();
    void RenderOpponent();
    bool getGameState();
    void Update();
    void Intialize();
    void Event();
    void Render();
    void Clear();
    int Random(int Min, int Max);
    bool IsDead();
    void PrintHighScore();
    bool GetHighScore();
    void PrintInfor();
    bool GetInfor();
    void EndGame();
    bool Loop();
   int Score();
};