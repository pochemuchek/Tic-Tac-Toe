#ifndef ARBITR_H
#define ARBITR_H
#include"field.h"

class ARBITR
{
private:
    int TypeGame;
    int Count_X;
    int Count_0;

public:
    ARBITR();
    int InitGame();

    bool CheckWinHorizontal(FIELD *Field);
    bool CheakWinVertical(FIELD *Field);
    bool CheakWinDiagLeft(FIELD *Field);
    bool CheakWinDiagRight(FIELD *Field);
    int CheckWinner(FIELD *Field);

};

#endif // ARBITR_H
