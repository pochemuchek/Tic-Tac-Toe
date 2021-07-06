#include<global.h>
#include "player.h"
#include "arbitr.h"
#include "field.h"
#include <iostream>

#include <QMap>
#include <QPair>

#ifndef GAMEPLAY_H
#define GAMEPLAY_H


class GamePlay
{
private:
    ARBITR* VadimArbitr;

    FIELD *field_TicTacToe;
    PLAYER *first;
    PLAYER *second;
    int  count_move;

public:
    void StartGame(int TypeGame);

    GamePlay(int TypeFirstPl, int TypeSecondPl, ARBITR*);
    ~GamePlay();

    std::pair<int, int> GetMove(char *NamePlayer);

    int MakeMovePlayer (PLAYER *player, char *NamePlayer);
    int MakeMoveAI (PLAYER *player);

    void Game_Human_VS_Ai(PLAYER *first, PLAYER *second);
    void Game_Human_VS_Human(PLAYER *first, PLAYER *second);
};

#endif // GAMEPLAY_H
