#ifndef ARBITR_H
#define ARBITR_H
#include"field.h"

class ARBITR
{
private:
    class FIELD *Field;

public:
    ARBITR();
    int InitGame();

    bool CheakWinHorizontal(FIELD *Field);
    bool CheakWinVertical(FIELD *Field);
    bool CheakWinDiagLeft(FIELD *Field);
    bool CheakWinDiagRight(FIELD *Field);
    int CheakWinner(FIELD *Field);

    int WinnerCount = 0;
    int TypeGame;
};

#endif // ARBITR_H
