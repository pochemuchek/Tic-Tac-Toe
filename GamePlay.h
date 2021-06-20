#include<global.h>
#include "player.h"
#include "field.h"
#include <iostream>
#ifndef GAMEPLAY_H
#define GAMEPLAY_H


class GamePlay
{
private:

    FIELD *field;
    PLAYER *first;
    PLAYER *second;
    int  count_move = 0;

public:
    GamePlay(int TypeFirstPl, int TypeSecondPl);
    ~GamePlay();

    std::pair<int, int> GetMove(char *NamePlayer);

    int MakeMovePlayer (FIELD *field, PLAYER *player, char *NamePlayer);
    int MakeMoveAI (FIELD *field, PLAYER *player, char *NamePlayer);

    void Game_Human_VS_Ai(FIELD *field, PLAYER *first, PLAYER *second);
    void Game_Human_VS_Human(FIELD *field, PLAYER *first, PLAYER *second);
};

#endif // GAMEPLAY_H
