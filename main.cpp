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

    GamePlay* game = new GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human, Vadim);
    game->StartGame(TYPE_GAME::HUMAN_VS_HUMAN);

    delete game;
    delete Vadim;

    return 0;

//    if(Vadim->InitGame() == 1)
//    {
//        GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human);
//    }
//    else if(Vadim->InitGame() == 2){
//        GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::AI);
//    }

//    delete Vadim;

        //GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human);
    return 0;
}
