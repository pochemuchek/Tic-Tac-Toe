#ifndef FIELD_H
#define FIELD_H
#include "global.h"
#include "player.h"
#include <iostream>


class FIELD
{
private :
   int **field;
   int w;
   int h;

   bool CheakWinHorizontal();
   bool CheakWinVertical();
   bool CheakWinDiagLeft();
   bool CheakWinDiagRight();

   friend class PLAYER;

public:

    int MaxMov = w*h;
    int count = 0;
    FIELD();
    ~FIELD();
    int isMovePossible(int x, int y);
    int MakeMoveF(int x, int y, char symb = SYMBOL::no);

    void ShowField();
    int CheckWinner();

    int X_count = 0;
    int O_count = 0;


};

#endif // FIELD_H
