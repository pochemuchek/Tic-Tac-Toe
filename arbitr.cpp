
#include "arbitr.h"

ARBITR::ARBITR()
{
    WinnerCount = 0;
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
    WinnerCount = 0;
    for(int i = 0; i < Field->hight; i++){
        for(int j = 0; j < Field->width; j++){
            if( Field->Field[i][j]== SYMBOL::tac && Field->Field[i][j] != SYMBOL::no){
                WinnerCount++;
            }
            else if(Field->Field[i][j] == SYMBOL::tic && Field->Field[i][j] != SYMBOL::no){
                WinnerCount++;
            }

            if(WinnerCount == Field->hight){
                return true;
            }
        }
    }
    return false;
}

bool ARBITR::CheckWinHorizontal(FIELD *Field)
{
    WinnerCount = 0;

    for(int i = 0; i < Field->hight; i++){
        for(int j = 0; j < Field->width; j++){
            if(Field->Field[j][i] == SYMBOL::tac && Field->Field[j][i] != SYMBOL::no){
                WinnerCount++;
            }
            else if(Field->Field[j][i] == SYMBOL::tic && Field->Field[j][i] != SYMBOL::no){
                WinnerCount++;
            }

            if(WinnerCount == Field->width){
                return true;
            }
        }
    }
    return false;
}

bool ARBITR::CheakWinDiagLeft(FIELD *Field)
{
    WinnerCount = 0;
    for(int i = 0; i < Field->width; i++){
        if(Field->Field[i][i] == SYMBOL::tac && Field->Field[i][i] != SYMBOL::no){
            WinnerCount++;
        }
        else if(Field->Field[i][i] == SYMBOL::tic && Field->Field[i][i] != SYMBOL::no){
            WinnerCount++;
        }
        if(WinnerCount == Field->width || WinnerCount == Field->hight){
            return true;
        }
    }
    return false;
}

bool ARBITR::CheakWinDiagRight(FIELD *Field)
{
    WinnerCount = 0;
    for(int i = Field->hight - 1; i >= 0; i--){
        for(int j = 0; j < Field->hight ; j++){
            if(Field->Field[i][j] == SYMBOL::tac && Field->Field[i][j] != SYMBOL::no){
                WinnerCount++;
            }
            else if(Field->Field[i][j] == SYMBOL::tic && Field->Field[i][j] != SYMBOL::no){
                WinnerCount++;
            }

        }
    }
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
