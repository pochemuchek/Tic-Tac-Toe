#include <QCoreApplication>
#include "player.h"
#include "GamePlay.h"
#include "field.h"
#include "arbitr.h"

#include <iostream>
using namespace std;


int main()
{
    ARBITR *Vadim = new ARBITR();
    GamePlay* game;
    int Point = Vadim->InitGame();

    if(Point == 1)
    {
         game = new GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human, Vadim);
         game->StartGame(TYPE_GAME::HUMAN_VS_HUMAN);
    }
    else if(Point == 2){
         game = new GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::AI, Vadim);
         game->StartGame(TYPE_GAME::HUMAN_VS_AI);
    }


    delete game;
    delete Vadim;

        //GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human);
    return 0;
}
