#include "field.h"
#include <cstdlib>
#include <iostream>


using namespace std;

FIELD::FIELD()
{
    w = 3;
    h = 3;
    width = 3;
    hight = 3;
    //заполняем все поля нулями
    // + инициализируем двумерный массив
    field = new int *[h];//выделяем новый столбик длинной h
    //и в этом столбике у каждого элемента ссылка остается на строку от этого столба
    for(int i = 0; i < h; i++){
        field[i] = new int [w];
        for (int j = 0; j < w; j++){
            field[i][j] = SYMBOL::no;
        }
    }
    Field = field;
}

FIELD::~FIELD()
{
    for(int i = 0; i < h ; i++){
        delete [] field[i];
    }
    delete [] field;
}

int FIELD::OpportunityOfMove(int x, int y){
    if(x >= w || y >= h){
        return ERRORS::INCORECT_COOR;
    }
    if(field[x][y] != SYMBOL::no ){
        return ERRORS::INCORECT_COOR;
    }

    return ERRORS::YES;
}

int FIELD::MakeMoveF(int x, int y, char symb)
{
    if(FIELD::OpportunityOfMove(x,y) == ERRORS::YES){
        field[x][y] = symb;
        return ERRORS::YES;
    }

    return ERRORS::INCORECT_COOR;
}


void FIELD::ShowField(){
    system("cls");

    cout << " |";
    for (int i = 0; i < w; i++) {
        cout << i << "|";
    }
    cout << endl;
    for (int y = 0; y < h; y++) {
        cout << y << "|";
        for (int x = 0; x < w; x++) {
            cout << (char)field[x][y] << "|";
        }
        cout << endl;
    }
    cout << endl;
}
