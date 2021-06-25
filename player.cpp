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

std::pair<std::pair<int, int>, char> PLAYER::GetInfo(int FirstFirst, int FirstSecond, int Second)
{
    std::pair<std::pair<int, int >, char>Information;
    Information.first.first = FirstFirst;// x coor
    Information.first.second = FirstSecond;// y cor
    Information.second = Second;// symb
    return Information;
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

std::pair<std::pair<int, int>, char> PLAYER::GetBetterMove(char symb, FIELD* current_field)
{

    if(count_move<1){
        count_move++;
        GetFirstMoveOnAngle(symb, current_field);
        return GetInfo(InformationFist.first.first, InformationFist.first.second, InformationFist.second.second);
    }
    else{
        return GetSecondMoveOnAngle(symb, current_field);
    }
}

void PLAYER::GetFirstMoveOnAngle(char symb, FIELD* current_field)
{
    std::cout<<"First";
    if(current_field->field[1][1] == SYMBOL::no){
        InformationFist.first.first = 1;
        InformationFist.first.second = 1;
        InformationFist.second.first = 1;
        InformationFist.second.second = symb;

    }
    else if(current_field->field[0][0] == SYMBOL::no &&
            current_field->field[1][1] != symb){
        InformationFist.first.first = 0;
        InformationFist.first.second = 0;
        InformationFist.second.first = 2;
        InformationFist.second.second = symb;

    }
    else if(current_field->field[0][0] != symb &&
            current_field->field[0][0] != SYMBOL::no &&
            current_field->field[2][0] == SYMBOL::no){
        InformationFist.first.first = 2;
        InformationFist.first.second = 0;
        InformationFist.second.first = 3;
        InformationFist.second.second = symb;

    }
    else if(current_field->field[2][0] != symb &&
            current_field->field[2][0] != SYMBOL::no &&
            current_field->field[2][2] == SYMBOL::no){
        InformationFist.first.first = 2;
        InformationFist.first.second = 2;
        InformationFist.second.first = 4;
        InformationFist.second.second = symb;

    }
    else if(current_field->field[2][2] != symb &&
             current_field->field[2][2] != SYMBOL::no &&
             current_field->field[0][2] == SYMBOL::no){
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
    if(InformationFist.second.first == 1){
        GetFirstMoveOnAngle(symb, current_field);
    }
    else if(InformationFist.second.first == 2){
        if(current_field->field[0][2] == SYMBOL::no){
            return GetInfo(0,2,symb);
        }
        else{
            return GetInfo(2,0,symb);
        }
    }
    else if(InformationFist.second.first == 3){
        if(current_field->field[2][2] == SYMBOL::no){
            return GetInfo(0,0,symb);
        }
        else{
            return GetInfo(2,2,symb);
        }
    }
    else if(InformationFist.second.first == 4){
        if(current_field->field[0][2] == SYMBOL::no){
            return GetInfo(0,2,symb);
        }
        else{
            return GetInfo(2,0,symb);
        }
    }
    else if(InformationFist.second.first == 5){
        if(current_field->field[0][0] == SYMBOL::no){
            return GetInfo(0,0,symb);
        }
        else{
            return GetInfo(2,2,symb);
        }
    }
        return GetInfo(-1,-1,symb);
}


std::pair<std::pair<int, int>, char> PLAYER::GetWinnerMove(char symb, FIELD* current_field)
{
    std::cout<<"Winner";

    for(int i = 0; i < 3; i++){//исчем где из верт/столбов есть два знака
        if(SearchForAi(0, symb, i, current_field) == true){//проверяем наличие двух знаков в одном из столбцов
            for(int j = 0; j <= i; j++){//исчем свободное место на этом столбе
                if(current_field->field[j][i] == SYMBOL::no){
                    return GetInfo(i,j,symb);//выводим координаты
               }
            }
        }
    }

    for(int i = 0; i < 3; i++){//исчем где из горизонтальных столбов есть два знака
        if(SearchForAi(1, symb, i, current_field) == true){//проверяем наличие двух знаков
            for(int j = 0; j <= i; j++){//ищем свободное место на этом столбе
                if(current_field->field[i][j] != symb){
                    return GetInfo(j,i,symb);//выводим координаты
                }
            }
        }
    }
    return GetInfo(-1,-1,symb);
}
