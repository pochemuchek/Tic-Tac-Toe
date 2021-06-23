#include "field.h"
#include <cstdlib>
#include <iostream>


using namespace std;

FIELD::FIELD()
{
    w = 3;
    h = 3;
    //заполняем все поля нулями
    // + инициализируем двумерный массив
    Field = new int *[h];//выделяем новый столбик длинной h

    //и в этом столбике у каждого элемента ссылка остается на строку от этого столба
    for(int i = 0; i < h; i++){
        Field[i] = new int [w];
        for (int j = 0; j < w; j++){
            Field[i][j] = SYMBOL::no;
        }
    }
}

FIELD::~FIELD()
{
    for(int i = 0; i < h ; i++){
        delete [] Field[i];
    }
    delete [] Field;
}

int FIELD::OpportunityOfMove(int x, int y){
    if(x > w || y > h){
        return ERRORS::INCORECT_COOR;
    }
    if(Field[x][y] != SYMBOL::no ){
        return ERRORS::INCORECT_COOR;
    }
    else{
        return 1;
    }
}

int FIELD::MakeMoveF(int x, int y, char symb)
{
    if(FIELD::OpportunityOfMove(x,y) == 1){
        Field[x][y] = symb;
        count++;
        return ERRORS::YES;
    }
    else{
         return -1;
    }
    return -1;
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
            cout << (char)Field[x][y] << "|";
        }
        cout << endl;
    }
    cout << endl;
}
