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
   friend class PLAYER;

public:

    int MaxMov = w*h;
    int width = w;
    int hight = h;
    int count = 0;
    int **Field = field; //copy for other functions outside this class (arbitr)
    FIELD();
    ~FIELD();

    int OpportunityOfMove(int x, int y);
    int MakeMoveF(int x, int y, char symb = SYMBOL::no);

    void ShowField();
    int CheakWinner();



};

#endif // FIELD_H
