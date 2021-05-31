#ifndef PLAYER_H
#define PLAYER_H

#include "field.h"
#include "global.h"
#include <iostream>

using namespace std;
class PLAYER
{
private:
    bool my_move;

    char symbol;
    int type_player;
    FIELD *current_field;

    std::pair<std::pair<int, int >, bool> GetWinnerMove();
    std::pair<std::pair<int, int>, bool> GetBetterMove() {}

   // std::pair<int, int> GetBetterMove() {}
public:
    PLAYER(FIELD* field, int type_pl, char symbol_player);
    int MakeMove(int x, int y);

};

#endif // PLAYER_H
