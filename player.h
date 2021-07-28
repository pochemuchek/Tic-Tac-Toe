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

    std::pair<std::pair<int, int >, char> GetInfo(int FirstFirst, int FirstSecond, int Second);
    std::pair<std::pair<int, int >, char> GetBetterMove(char symb);

    int GetFirstMoveOnAngle(char symb, FIELD* field);
    int GetSecondMoveOnAngle(char symb, FIELD* field);
    void GetThirdMoveOnAngle(char symb, FIELD* field);

    int TypeFirstMove;
    int TypeSecondMove;

    std::pair<std::pair<int, int >, char> PreventWin(char symb);
    std::pair<std::pair<int, int >, char> GetWinnerMove(char symb, FIELD* field);
    std::pair<int, int> SearchWinnerMoveForLine(FIELD* field, int line, int search);
    std::pair<int, int > SearchWinnerMoveForDiag(FIELD* field, char symb, int search);

    int move = 0;
public:

    PLAYER(FIELD* field, int type_pl, char symbol_player);
    int MakeMovePL(int x, int y, char type_player, FIELD* field);
    bool SearchForAi(int type_search, char symb, int line, FIELD* field);
    // if type_search = 0 is horizontal search
    // if type_search = 1 is vertical search

    int type_player;
    int count = 0;
    int count_move = 0;
    std::pair<std::pair<int, int >, char> InformationFirst;
    std::pair<std::pair<int, int >, char> InformationSecond;
    std::pair<std::pair<int, int >, char> InformationThird;

};

#endif // PLAYER_H
