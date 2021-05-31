#include "player.h"
#include "field.h"
#include <iostream>
using namespace std;



PLAYER::PLAYER(FIELD *field, int type_pl, char symbol_player)
{
    type_player = type_pl;
    symbol = symbol_player;
    current_field = field;

    my_move = false;

    if(my_move == SYMBOL::tac){
        my_move = true;
    }
}

int PLAYER::MakeMove(int x, int y)
{
    if(type_player == TYPE_PLAYER::human){
        return current_field->MakeMove(x,y,symbol);
    }
//    if(type_player == TYPE_PLAYER::AI){
//        if(GetWinnerMove().first.first == -1){
//            return current_field->MakeMove(GetBetterMove().first.first,
//                                           GetBetterMove().first.second,
//                                           GetBetterMove().second);
//        }else{
//            return current_field->MakeMove(GetWinnerMove().first.first,
//                                           GetWinnerMove().first.second,
//                                           GetWinnerMove().second);
//        }
//    }
}


