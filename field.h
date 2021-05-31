#ifndef FIELD_H
#define FIELD_H
#include "global.h"
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

public:
    int MaxMov = w*h;
    int count = 0;
    FIELD();
    ~FIELD();
    int OpportunityOfMove(int x, int y);
    int MakeMove(int x, int y, char symb = SYMBOL::no);

    void ShowField();
    int CheakWinner();

};

#endif // FIELD_H
