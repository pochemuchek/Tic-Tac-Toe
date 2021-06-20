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
    class FIELD *current_field;

    std::pair<std::pair<int, int >, char> GetWinnerMove(char symb, FIELD* field);
    std::pair<std::pair<int, int >, char> GetBetterMove(char symb, FIELD* field);
    void GetFirstMoveOnAngle(char symb, FIELD* field);
    std::pair<std::pair<int, int >, char> GetSecondMoveOnAngle(char symb, FIELD* field);

    int move = 0;
public:
    int type_player;
    int count = 0;
    PLAYER(FIELD* field, int type_pl, char symbol_player);
    int MakeMovePL(int x, int y, char type_player, FIELD* field);
    int count_move = 0;
    std::pair<std::pair<int, int>,std::pair<int, char>> InformationFist;

    bool SearchForAi(int type_search, char symb, int line, FIELD* field);
    // if type_search = 0 is horizontal search
    // if type_search = 1 is vertical search
};

#endif // PLAYER_H
