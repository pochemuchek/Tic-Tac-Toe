#include <QCoreApplication>
#include "player.h"
#include "GamePlay.h"
#include "field.h"
#include "arbitr.h"
#include <iostream>
using namespace std;

int main()
{
    ARBITR *Vadim;
    if(Vadim->InitGame() == 1){
        GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human);
    }
    else{
        GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::AI);
    }
    return 1;
}
