
#include "arbitr.h"

ARBITR::ARBITR()
{
    Count_0 = 0;
    Count_X = 0;
    TypeGame = 0;
}
int ARBITR::CheckWinner(FIELD *Field)
{
    if(CheckWinHorizontal(Field) == true){
        return ERRORS::WIN;
    }
    if(CheakWinVertical(Field) == true){
        return ERRORS::WIN;
    }
    if(CheakWinDiagLeft(Field) == true){
        return ERRORS::WIN;
    }
    if(CheakWinDiagRight(Field) == true){
        return ERRORS::WIN;
    }
    return ERRORS::NEXT_MOVE;
}

bool ARBITR::CheakWinVertical(FIELD *Field)
{
    for(int i = 0; i < Field->hight; i++){
        for(int j = 0; j < Field->width; j++){
            if( Field->Field[i][j] == SYMBOL::tac && Field->Field[i][j] != SYMBOL::no){
                Count_0++;
            }
            else if(Field->Field[i][j] == SYMBOL::tic && Field->Field[i][j] != SYMBOL::no){
                Count_X++;
            }
        }
        if(Count_X == Field->hight || Count_0 == Field->hight){
            cout<<"v";
            return true;
        }
        Count_0 = 0;
        Count_X = 0;
    }
    Count_0 = 0;
    Count_X = 0;
    return false;
}

bool ARBITR::CheckWinHorizontal(FIELD *Field)
{
    for(int i = 0; i < Field->hight; i++){
        for(int j = 0; j < Field->width; j++){

            if(Field->Field[j][i] == SYMBOL::tac && Field->Field[j][i] != SYMBOL::no){
                Count_0++;
            }
            else if(Field->Field[j][i] == SYMBOL::tic && Field->Field[j][i] != SYMBOL::no){
                Count_X++;
            }
        }
        if(Count_X == Field->width || Count_0 == Field->width){
            cout<<"h";
            return true;
        }
        Count_0 = 0;
        Count_X = 0;
    }
    Count_0 = 0;
    Count_X = 0;
    return false;
}

bool ARBITR::CheakWinDiagLeft(FIELD *Field)
{
    for(int i = 0; i < Field->width; i++){
        if(Field->Field[i][i] == SYMBOL::tac && Field->Field[i][i] != SYMBOL::no){
            Count_0++;
        }
        else if(Field->Field[i][i] == SYMBOL::tic && Field->Field[i][i] != SYMBOL::no){
            Count_X++;
        }
        if(Count_X == Field->width || Count_0 == Field->hight){
            cout<<"dl";
            Count_0 = 0;
            Count_X = 0;
            return true;
        }
    }
    Count_0 = 0;
    Count_X = 0;
    return false;
}

bool ARBITR::CheakWinDiagRight(FIELD *Field)
{
    int i = (Field->hight - 1);
    int j = 0;
    while(j < 3 && i >= 0){
            if(Field->Field[i][j] != SYMBOL::tic && Field->Field[i][j] == SYMBOL::tac &&
               Field->Field[i][j] == SYMBOL::no){
                Count_0++;
            }
            else if(Field->Field[i][j] == SYMBOL::tic && Field->Field[i][j] != SYMBOL::no &&
                    Field->Field[i][j] != SYMBOL::tac){
                Count_X++;
            }
            j++;
            i--;
        }
        if(Count_X == 3 || Count_0 == 3){
            Count_0 = 0;
            Count_X = 0;
            return true;
        }
    Count_0 = 0;
    Count_X = 0;
    return false;
}

int ARBITR::InitGame()
{
    do{
    cout << "Choose type game" << endl << "write (1) Human VS Human game"
    << endl << "Write (2) Human VS Artificial intellect game" << endl;;
    cin >> TypeGame;
    }while(TypeGame == 0);

    return TypeGame;
}
