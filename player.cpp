#include "player.h"
#include "field.h"
#include "global.h"
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

int PLAYER::MakeMovePL(int x, int y, char type_player, FIELD* current_field)
{
    if(type_player == TYPE_PLAYER::human){
        return current_field->MakeMoveF(x,y,symbol);
    }
    else if(type_player == TYPE_PLAYER::AI){
        std::cout<<"MAkeMOve";
        std::pair<std::pair<int, int>, char> InformationMM;
        if(GetWinnerMove(symbol, current_field).first.first == -1){
            InformationMM = GetBetterMove(symbol, current_field);
            return current_field->MakeMoveF(InformationMM.first.second,//информация правильно доходит
                                           InformationMM.first.first,
                                           InformationMM.second);

        }else{
            InformationMM = GetWinnerMove(symbol, current_field);
            return current_field->MakeMoveF(InformationMM.first.first,
                                           InformationMM.first.second,
                                           InformationMM.second);
        }
    }
    return ERRORS::YES;
}

bool PLAYER::SearchForAi(int type_search, char symb, int line, FIELD* current_field)
{
    count = 0;
    switch(type_search){
        case 0://horizontal search
        std::cout<<"horizontal search ai";

          for(int j = 0; j < current_field->h; j++){
              if(current_field->Field[j][line] == symb){
                  count++;
           }
          }
          if (count == 2){
            return true;
          }
          else{
            return false;
          }

            break;
        case 1://vertical search
        std::cout<<" Verticsl ai";

           for(int j = 0; j < current_field->w; j++){
               if(current_field->Field[line][j] == symb){
                   count++;
               }
              }
           if (count == 2){
             return true;
           }
           else{
             return false;
           }
            break;
            default:
        return false;
    }
}

std::pair<std::pair<int, int>, char> PLAYER::GetBetterMove(char symb, FIELD* current_field)
{
    std::pair<std::pair<int, int>, char> InformationBM;

    if(count_move<1){
        count_move++;
        GetFirstMoveOnAngle(symb, current_field);
        InformationBM.first.first = InformationFist.first.first;
        InformationBM.first.second = InformationFist.first.second;
        InformationBM.second = InformationFist.second.second;
        return InformationBM;
    }
    else{
        return GetSecondMoveOnAngle(symb, current_field);
    }
}

void PLAYER::GetFirstMoveOnAngle(char symb, FIELD* current_field)
{
    std::cout<<"First";
    if(current_field->Field[1][1] == SYMBOL::no){
        InformationFist.first.first = 1;
        InformationFist.first.second = 1;
        InformationFist.second.first = 1;
        InformationFist.second.second = symb;

    }
    else if(current_field->Field[0][0] == SYMBOL::no &&
            current_field->Field[1][1] != symb){
        InformationFist.first.first = 0;
        InformationFist.first.second = 0;
        InformationFist.second.first = 2;
        InformationFist.second.second = symb;

    }
    else if(current_field->Field[0][0] != symb &&
            current_field->Field[0][0] != SYMBOL::no &&
            current_field->Field[2][0] == SYMBOL::no){
        InformationFist.first.first = 2;
        InformationFist.first.second = 0;
        InformationFist.second.first = 3;
        InformationFist.second.second = symb;

    }
    else if(current_field->Field[2][0] != symb &&
            current_field->Field[2][0] != SYMBOL::no &&
            current_field->Field[2][2] == SYMBOL::no){
        InformationFist.first.first = 2;
        InformationFist.first.second = 2;
        InformationFist.second.first = 4;
        InformationFist.second.second = symb;

    }
    else if(current_field->Field[2][2] != symb &&
             current_field->Field[2][2] != SYMBOL::no &&
             current_field->Field[0][2] == SYMBOL::no){
         InformationFist.first.first = 0;
         InformationFist.first.second = 2;
         InformationFist.second.first = 5;
         InformationFist.second.second = symb;

    }else{
    InformationFist.first.first = 2;
    InformationFist.first.second = 2;
    InformationFist.second.first = 6;
    InformationFist.second.second = symb;

    }
}

std::pair<std::pair<int, int>, char> PLAYER::GetSecondMoveOnAngle(char symb, FIELD* current_field)
{
    std::cout<<"Second";
    std::pair<std::pair<int, int>, char> InformationSecond;
    if(InformationFist.second.first == 1){
        GetFirstMoveOnAngle(symb, current_field);
    }
    else if(InformationFist.second.first == 2){
        if(current_field->Field[0][2] == SYMBOL::no){
            InformationSecond.first.first = 0;
            InformationSecond.first.second = 2;
            InformationSecond.second = symb;
            return InformationSecond;
        }
        else{
            InformationSecond.first.first = 2;
            InformationSecond.first.second = 0;
            InformationSecond.second = symb;
            return InformationSecond;
        }
    }
    else if(InformationFist.second.first == 3){
        if(current_field->Field[2][2] == SYMBOL::no){
            InformationSecond.first.first = 0;
            InformationSecond.first.second = 0;
            InformationSecond.second = symb;
            return InformationSecond;
        }
        else{
            InformationSecond.first.first = 2;
            InformationSecond.first.second = 2;
            InformationSecond.second = symb;
            return InformationSecond;
        }
    }
    else if(InformationFist.second.first == 4){
        if(current_field->Field[0][2] == SYMBOL::no){
            InformationSecond.first.first = 0;
            InformationSecond.first.second = 2;
            InformationSecond.second = symb;
            return InformationSecond;
        }
        else{
            InformationSecond.first.first = 2;
            InformationSecond.first.second = 0;
            InformationSecond.second = symb;
            return InformationSecond;
        }
    }
    else if(InformationFist.second.first == 5){
        if(current_field->Field[0][0] == SYMBOL::no){
            InformationSecond.first.first = 0;
            InformationSecond.first.second = 0;
            InformationSecond.second = symb;
            return InformationSecond;
        }
        else{
            InformationSecond.first.first = 2;
            InformationSecond.first.second = 2;
            InformationSecond.second = symb;
            return InformationSecond;
        }
    }
        InformationSecond.first.first = -1;
        return InformationSecond;
}

std::pair<std::pair<int, int>, char> PLAYER::GetWinnerMove(char symb, FIELD* current_field)
{
    std::cout<<"Winner";
    std::pair<std::pair<int, int>, char> InformationWM;

    for(int i = 0; i < 3; i++){//исчем где из верт/столбов есть два знака
        if(SearchForAi(0, symb, i, current_field) == true){//проверяем наличие двух знаков в одном из столбцов
            for(int j = 0; j <= i; j++){//исчем свободное место на этом столбе
                if(current_field->Field[j][i] == SYMBOL::no){
                    InformationWM.first.first = i;
                    InformationWM.first.second = j;
                    InformationWM.second = symb;
                    return InformationWM;//выводим координаты
               }
            }
        }
    }

    for(int i = 0; i < 3; i++){//исчем где из горизонтальных столбов есть два знака
        if(SearchForAi(1, symb, i, current_field) == true){//проверяем наличие двух знаков
            for(int j = 0; j <= i; j++){//ищем свободное место на этом столбе
                if(current_field->Field[i][j] != symb){
                    InformationWM.first.first = j;
                    InformationWM.first.second = i;
                    InformationWM.second = symb;
                    return InformationWM;//выводим координаты
                }
            }
        }
    }
    InformationWM.first.first = -1;
    return InformationWM;
}
