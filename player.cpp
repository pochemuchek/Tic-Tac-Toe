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
        if(GetWinnerMove(symbol, current_field).first.first == -1 && PreventWin(symbol).first.first == -1){
            InformationMM = GetBetterMove(symbol);
            return current_field->MakeMoveF(InformationMM.first.second,//информация правильно доходит
                                           InformationMM.first.first,
                                           InformationMM.second);

        }
        else if(PreventWin(symbol).first.first != -1){
            InformationMM = PreventWin(symbol);
            return current_field->MakeMoveF(InformationMM.first.first,
                                            InformationMM.first.second,
                                            SYMBOL::tac);//can be smth wrong
        }
        else{
            InformationMM = GetWinnerMove(symbol, current_field);
            return current_field->MakeMoveF(InformationMM.first.first,
                                           InformationMM.first.second,
                                           InformationMM.second);
        }
    }
    return ERRORS::YES;
}


std::pair<std::pair<int, int>, char> PLAYER::GetBetterMove(char symb)
{

    if(count_move<2){
        count_move++;
        GetFirstMoveOnAngle(symb, current_field);
        return GetInfo(InformationFist.first.first, InformationFist.first.second, InformationFist.second);
    }
    else{
        return GetSecondMoveOnAngle(symb, current_field);
    }
}

int PLAYER::GetFirstMoveOnAngle(char symb, FIELD* current_field)
{
    if(current_field->field[1][1] == SYMBOL::no){ // GetInfo return first x, second y, third symb
        InformationFist = GetInfo(1, 1, symb);
        return 1;

    }
    else if(current_field->field[0][0] == SYMBOL::no){
        InformationFist = GetInfo(0, 0, symb);
        return 2;

    }
    else if(current_field->field[2][0] == SYMBOL::no){
        InformationFist = GetInfo(2, 0, symb);
        return 3;

    }
    else if(current_field->field[2][2] == SYMBOL::no){
        InformationFist = GetInfo(2, 2, symb);
        return 4;

    }
    else if(current_field->field[0][2] == SYMBOL::no){
         InformationFist = GetInfo(0, 2, symb);
         return 5;

    }else{
    InformationFist = GetInfo(0, 2, symb);
    return 6;
    }
}

std::pair<std::pair<int, int>, char> PLAYER::GetSecondMoveOnAngle(char symb, FIELD* current_field)
{
    std::cout<<"Second";
    int TypeFirstMove = GetFirstMoveOnAngle(symb, current_field);

    if(TypeFirstMove == 1){
        GetFirstMoveOnAngle(symb, current_field);
    }
    else if(TypeFirstMove == 2){
        if(current_field->field[2][0] == SYMBOL::no){
            return GetInfo(2,0,symb);
        }
        else{
            return GetInfo(0,2,symb);
        }
    }
    else if(TypeFirstMove == 3){
        if(current_field->field[2][2] == SYMBOL::no){
            return GetInfo(0,0,symb);
        }
        else{
            return GetInfo(2,2,symb);
        }
    }
    else if(TypeFirstMove == 4){
        if(current_field->field[0][2] == SYMBOL::no){
            return GetInfo(0,2,symb);
        }
        else{
            return GetInfo(2,0,symb);
        }
    }
    else if(TypeFirstMove == 5){
        if(current_field->field[0][0] == SYMBOL::no){
            return GetInfo(0,0,symb);
        }
        else{
            return GetInfo(2,2,symb);
        }
    }
    return GetInfo(-1,-1,symb);
}

std::pair<std::pair<int, int>, char> PLAYER::PreventWin(char symbol)
{
    if(symbol == SYMBOL::tac){// this is using to understand which symbol have human
        symbol = SYMBOL::tic;
    }else{
        symbol = SYMBOL::tac;
    }

   return GetWinnerMove(symbol, current_field);
}


std::pair<std::pair<int, int>, char> PLAYER::GetWinnerMove(char symb, FIELD* current_field)
{
    std::cout<<"Winner";
    std::pair<int, int> Info;
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
    std::cout<<"searchWINNERlINE";
    std::pair<int, char> Info;
    switch (search) {
        case 0://vert
        for(int i = 0; i <= current_field->w; i++){
            if(current_field->field[line][i] == SYMBOL::no){
                Info.first = line;
                Info.second = i;
                return Info;
            }
        }
        break;
        case 1://horiz
        for(int i = 0; i <= current_field->w; i++){
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
   std::cout<<"searchWINNERDIAGКК";
   std::pair<int, int> Info;
   switch(search){
   case 0://diag right
   {
           int i = 2;
           int j = 0;
           while(i > 0 && j < 3){
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
            int i = 2;
            int j = 0;
            while(i >= 0 && j < 3){
                if(current_field->field[i][j] == symb){
                    count++;
                }
                i--;
                j++;
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

