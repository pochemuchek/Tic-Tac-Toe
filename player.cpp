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

int PLAYER::MakeMovePL(int x, int y, char type_player)
{
    std::cout<<"MAkeMOve";
    std::pair<std::pair<int, int>, char> Information;
    if(type_player == TYPE_PLAYER::human){
        return current_field->MakeMoveF(x,y,symbol);
    }
    else if(type_player == TYPE_PLAYER::AI){
        if(GetWinnerMove(symbol).first.first == -1){
            Information = GetBetterMove(symbol);
            return current_field->MakeMoveF(Information.first.second,
                                           Information.first.first,
                                           Information.second);

        }else{
            Information = GetWinnerMove(symbol);
            return current_field->MakeMoveF(Information.first.first,
                                           Information.first.second,
                                           Information.second);
        }
    }
    return ERRORS::YES;
}

bool PLAYER::SearchForAi(int type_search, char symb, int line)
{
    count = 0;
    switch(type_search){
        case 0://horizontal search
        std::cout<<"horizontal search ai";

          for(int j = 0; j < current_field->h; j++){
              if(current_field->field[j][line] == symb){
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
               if(current_field->field[line][j] == symb){
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

std::pair<std::pair<int, int>, char> PLAYER::GetBetterMove(char symb)
{
    std::pair<std::pair<int, int>,std::pair<int, char>> Infor;
    std::pair<std::pair<int, int>, char> Information;

    if(count_move<1){
        count_move++;
        GetFirstMoveOnAngle(symb) = Infor;
        Information.first.first = Infor.first.first;
        Information.first.first = Infor.first.second;
        Information.second = Infor.second.second;
        return Information;
    }
    else{
        return GetSecondMoveOnAngle(symb);
    }
}

std::pair<std::pair<int, int>,std::pair<int, char>> PLAYER::GetFirstMoveOnAngle(char symb)
{
    std::cout<<"First";
    std::pair<std::pair<int, int>,std::pair<int, char>> Information;//пара пар
    if(current_field->field[1][1] == SYMBOL::no){
        Information.first.first = 1;
        Information.first.second = 1;
        Information.second.first = 1;
        Information.second.second = symb;
        return Information;
    }
    else if(current_field->field[0][0] == SYMBOL::no &&
            current_field->field[1][1] != symb){
        Information.first.first = 0;
        Information.first.second = 0;
        Information.second.first = 2;
        Information.second.second = symb;
        return Information;
    }
    else if(current_field->field[0][0] != symb &&
            current_field->field[0][0] != SYMBOL::no &&
            current_field->field[2][0] == SYMBOL::no){
        Information.first.first = 2;
        Information.first.second = 0;
        Information.second.first = 3;
        Information.second.second = symb;
        return Information;
    }
    else if(current_field->field[2][0] != symb &&
            current_field->field[2][0] != SYMBOL::no &&
            current_field->field[2][2] == SYMBOL::no){
        Information.first.first = 2;
        Information.first.second = 2;
        Information.second.first = 4;
        Information.second.second = symb;
        return Information;
    }
    else if(current_field->field[2][2] != symb &&
             current_field->field[2][2] != SYMBOL::no &&
             current_field->field[0][2] == SYMBOL::no){
         Information.first.first = 0;
         Information.first.second = 2;
         Information.second.first = 5;
         Information.second.second = symb;
         return Information;
    }
    Information.second.first = -1;
    return Information;
}

std::pair<std::pair<int, int>, char> PLAYER::GetSecondMoveOnAngle(char symb)
{
    std::cout<<"Second";
    std::pair<std::pair<int, int>, char> Information;
    if(GetFirstMoveOnAngle(symb).second.second == 1){
        GetFirstMoveOnAngle(symb);
    }
    else if(GetFirstMoveOnAngle(symb).second.second == 2){
        if(current_field->field[0][2] == SYMBOL::no){
            Information.first.first = 0;
            Information.first.second = 2;
            Information.second = symb;
            return Information;
        }
        else{
            Information.first.first = 2;
            Information.first.second = 0;
            Information.second = symb;
            return Information;
        }
    }
    else if(GetFirstMoveOnAngle(symb).second.second == 3){
        if(current_field->field[2][2] == SYMBOL::no){
            Information.first.first = 0;
            Information.first.second = 0;
            Information.second = symb;
            return Information;
        }
        else{
            Information.first.first = 2;
            Information.first.second = 2;
            Information.second = symb;
            return Information;
        }
    }
    else if(GetFirstMoveOnAngle(symb).second.second == 4){
        if(current_field->field[0][2] == SYMBOL::no){
            Information.first.first = 0;
            Information.first.second = 2;
            Information.second = symb;
            return Information;
        }
        else{
            Information.first.first = 2;
            Information.first.second = 0;
            Information.second = symb;
            return Information;
        }
    }
    else if(GetFirstMoveOnAngle(symb).second.second == 5){
        if(current_field->field[0][0] == SYMBOL::no){
            Information.first.first = 0;
            Information.first.second = 0;
            Information.second = symb;
            return Information;
        }
        else{
            Information.first.first = 2;
            Information.first.second = 2;
            Information.second = symb;
            return Information;
        }
    }
        Information.first.first = -1;
        return Information;
}

std::pair<std::pair<int, int>, char> PLAYER::GetWinnerMove(char symb)
{
    std::cout<<"Winner";
    std::pair<std::pair<int, int>, char> Information;

    for(int i = 0; i < 3; i++){//исчем где из верт/столбов есть два знака
        if(SearchForAi(0,symb,i) == true){//проверяем наличие двух знаков в одном из столбцов
            for(int j = 0; j <= i; j++){//исчем свободное место на этом столбе
                if(current_field->field[j][i] == SYMBOL::no){
                    Information.first.first = i;
                    Information.first.second = j;
                    Information.second = symb;
                    return Information;//выводим координаты
               }
            }
        }
    }

    for(int i = 0; i < 3; i++){//исчем где из горизонтальных столбов есть два знака
        if(SearchForAi(1,symb,i) == true){//проверяем наличие двух знаков
            for(int j = 0; j <= i; j++){//ищем свободное место на этом столбе
                if(current_field->field[i][j] != symb){
                    Information.first.first = j;
                    Information.first.second = i;
                    Information.second = symb;
                    return Information;//выводим координаты
                }
            }
        }
    }
    Information.first.first = -1;
    return Information;
}
