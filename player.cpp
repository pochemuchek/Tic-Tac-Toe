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
        std::cout<<"MAkeMOve  ";
        std::pair<std::pair<int, int>, char> InformationGWM, InformationPW;
        InformationGWM = GetWinnerMove(symbol, current_field);
        InformationPW = PreventWin(symbol);
        if(InformationGWM.first.first != -1){
                    return current_field->MakeMoveF(InformationGWM.first.first,
                                                    InformationGWM.first.second,
                                                    InformationGWM.second);

        }
        else if(InformationGWM.first.first == -1 && InformationPW.first.first != -1){
            return current_field->MakeMoveF(InformationPW.first.first,
                                           InformationPW.first.second,
                                           SYMBOL::tac);
        }
        else{
            InformationGWM = GetBetterMove(symbol);
            return current_field->MakeMoveF(InformationGWM.first.first,
                                            InformationGWM.first.second,
                                            InformationGWM.second);
        }
    }
    return ERRORS::YES;
}


std::pair<std::pair<int, int>, char> PLAYER::GetBetterMove(char symb)
{

    if(count_move = 1){
        count_move++;
        TypeFirstMove = GetFirstMoveOnAngle(symb, current_field);
        return GetInfo(InformationFirst.first.first, InformationFirst.first.second, InformationFirst.second);
    }
    else if (count_move = 2){
        count_move++;
        TypeSecondMove = GetSecondMoveOnAngle(symb, current_field);
        return InformationSecond;
    }else{
        return InformationThird;
    }
}

int PLAYER::GetFirstMoveOnAngle(char symb, FIELD* current_field)
{
    if(current_field->field[1][1] == SYMBOL::no){ // GetInfo return first x, second y, third symb
        InformationFirst = GetInfo(1, 1, symb);
        return 1;

    }
    else if(current_field->field[0][0] == SYMBOL::no){
        InformationFirst = GetInfo(0, 0, symb);
        return 2;

    }
    else if(current_field->field[2][0] == SYMBOL::no){
        InformationFirst = GetInfo(2, 0, symb);
        return 3;

    }
    else if(current_field->field[2][2] == SYMBOL::no){
        InformationFirst = GetInfo(2, 2, symb);
        return 4;

    }
    else if(current_field->field[0][2] == SYMBOL::no){
         InformationFirst = GetInfo(0, 2, symb);
         return 5;

    }else{
    return -1;
    }
}

int PLAYER::GetSecondMoveOnAngle(char symb, FIELD* current_field)
{
    std::cout<<"Second";
    if(TypeFirstMove == 1){
        GetFirstMoveOnAngle(symb, current_field);
    }
    else if(TypeFirstMove == 2){
        if(current_field->field[2][2] == SYMBOL::no){
            InformationSecond = GetInfo(2,2,symb);
            return 2;
        }

    }
    else if(TypeFirstMove == 3){
        if(current_field->field[0][2] == SYMBOL::no){
            InformationSecond = GetInfo(0,2,symb);
            return 3;
        }
    }
    else if(TypeFirstMove == 4){
        if(current_field->field[1][0] == SYMBOL::no){
            InformationSecond = GetInfo(1,0,symb);
            return 41;
        }
        else{
            InformationSecond = GetInfo(0,1,symb);
            return 42;
        }
    }
    else if(TypeFirstMove == 5){
        if(current_field->field[1][0] == SYMBOL::no){
            InformationSecond = GetInfo(1,0,symb);
            return 51;
        } else{
            InformationSecond = GetInfo(0,1,symb);
            return 52;
        }
    }
    else if(TypeFirstMove == -1){
        if(current_field->field[2][1] == SYMBOL::no){
            InformationSecond = GetInfo(2,1,symb);
            return 6;
        }
    }
    return -1;
}

void PLAYER::GetThirdMoveOnAngle(char symb, FIELD* current_field)
{
    if(TypeSecondMove == 2){
        if(current_field->field[0][2] == SYMBOL::no){
            InformationThird = GetInfo(0,2,symb);
        }
        else{
            InformationThird = GetInfo(2,0,symb);
        }

    }
    else if(TypeSecondMove == 3){
        if(current_field->field[2][2] == SYMBOL::no){
            InformationThird = GetInfo(2,2,symb);
        }
        else{
            InformationThird = GetInfo(0,0,symb);
        }
    }
    else if(TypeSecondMove == 41){
        if(current_field->field[0][1] == SYMBOL::no){
            InformationThird = GetInfo(0,1,symb);
        }
        else{
            InformationThird = GetInfo(2,1,symb);
        }
    }
    else if(TypeSecondMove == 42){
        if(current_field->field[1][2] == SYMBOL::no){
            InformationThird = GetInfo(1,2,symb);
        }
        else{
            InformationThird = GetInfo(2,1,symb);
        }
    }
    else if(TypeSecondMove == 6){
        if(current_field->field[1][0] == SYMBOL::no){
            InformationThird = GetInfo(1,0,symb);
        }
        else{
            InformationThird = GetInfo(1,2,symb);
        }
    }
}

std::pair<std::pair<int, int>, char> PLAYER::PreventWin(char symbol)
{
    char symb;
    if(symbol == SYMBOL::tac){// this is using to understand which symbol have human
        symb = SYMBOL::tic;
    }else{
        symb = SYMBOL::tac;
    }
    pair<pair<int, int>, char> Info = GetWinnerMove(symb, current_field);
   return GetInfo(Info.first.first, Info.first.second, symbol);

}


pair<pair<int, int>, char> PLAYER::GetWinnerMove(char symb, FIELD* current_field)
{
    cout<<"Winner";
    pair<int, int> Info;
    for(int i = 0; i < 3; i++){//исчем где из верт/столбов есть два знака
        if(SearchForAi(1, symb, i, current_field) == true){//проверяем наличие двух знаков в одном из столбцов
            Info = SearchWinnerMoveForLine(current_field, i, 0);
            return  GetInfo(Info.first, Info.second, symb);
        }
    }

    for(int i = 0; i < 3; i++){//исчем где из горизонтальных столбов есть два знака
        if(SearchForAi(0, symb, i, current_field) == true){//проверяем наличие двух знаков
            Info = SearchWinnerMoveForLine(current_field, i, 1);
            return  GetInfo(Info.first, Info.second, symb);
        }
    }

    if(SearchForAi(2, symb, -1, current_field) == true){//правая диагональ
        Info = SearchWinnerMoveForDiag(current_field, symb, 0);
        return GetInfo(Info.first, Info.second, symb);
    }

    if(SearchForAi(3, symb, -1, current_field) == true){//левая диагональ
        Info = SearchWinnerMoveForDiag(current_field, symb, 1);
        return GetInfo(Info.first, Info.second, symb);
    }
    return GetInfo(-1,-1,symb);
}
std::pair<int, int> PLAYER::SearchWinnerMoveForLine(FIELD *current_field, int line, int search)
{
    cout<<"searchWINNERlINE";
    pair<int, char> Info;
    switch (search) {
        case 0://vert
        cout<<0;
        for(int i = 0; i < current_field->w; i++){
            if(current_field->field[line][i] == SYMBOL::no){
                Info.first = line;
                Info.second = i;
                return Info;
            }
        }
        break;
        case 1://horiz
        cout<<1;
        for(int i = 0; i < current_field->w; i++){
            if(current_field->field[i][line] == SYMBOL::no){
                Info.first = i;
                Info.second = line;
                return Info;
            }
        }
    }
    Info.first = -1;
    Info.second = -1;
    return Info;
}
std::pair<int, int> PLAYER::SearchWinnerMoveForDiag(FIELD* current_field, char symb, int search)
{
   std::cout<<"searchWINNERDIAG";
   std::pair<int, int> Info;
   switch(search){
   case 0://diag right
   {
           int i = 2;
           int j = 0;
           while(i >= 0 && j < 3){
               if(current_field->Field[i][j] != symb && current_field->Field[i][j] == SYMBOL::no){
                   Info.first = i;
                   Info.second = j;
                   return Info;
               }
               i--;
               j++;
           }
           return Info;
   }
   case 1://diag left
       for(int i = 0; i < current_field->width; i++){
           if(current_field->Field[i][i] != symb && current_field->Field[i][i] == SYMBOL::no){
               Info.first = i;
               Info.second = i;
               return Info;
           }
       }
   }
   Info.first = -1;
   Info.second = -1;
   return Info;
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
            return false;
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
            return false;
            break;
        case 2:// diag right
    {
            for(int i = 2, j = 0; i >= 0 && j <= 2; i--, j++){
                if(current_field->field[i][j] == symb){
                    count++;
                }
                if (current_field->field[i][j] != SYMBOL::no && current_field->field[i][j] != symb){
                    return false;
                }
            }
            if(count == 2){
                return true;
            }
            return false;
    }
            break;
        case 3://diag left
            for(int i = 0; i < current_field->w; i++){
                if(current_field->field[i][i] == symb){
                    count++;
                }
            }
            if(count == 2){
                return true;
            }
            count = 0;
            return false;
        break;
    default:
        return false;
    }
}

