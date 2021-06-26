#include <QCoreApplication>
#include "player.h"
#include "GamePlay.h"
#include "field.h"
#include "arbitr.h"

#include <iostream>
using namespace std;

class TEMP {
public :
//    static int a;
    int b;
};
//int TEMP::a = 0;

void foo(TEMP* a) {
    std::cout << a->b;
    a->b = 100;
}


int main()
{
    ARBITR *Vadim = new ARBITR();

    GamePlay* game = new GamePlay(TYPE_PLAYER::human, TYPE_PLAYER::human, Vadim);


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
