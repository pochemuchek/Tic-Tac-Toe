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
    count_move = 0;
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

int FIELD::getCount_move()
{
    return count_move;
}

int FIELD::OpportunityOfMove(int x, int y){
    int error = ERRORS::YES;
    if (count_move > 8) {
        error = ERRORS::NOT_POSSIBLE_MOVE;
    }
    else if(x >= w || y >= h){
        error = ERRORS::INCORECT_COOR;
    }
    else if(field[x][y] != SYMBOL::no ){
        error = ERRORS::INCORECT_COOR;
    }
    count_move++;
    return error;
}

int FIELD::MakeMoveF(int x, int y, char symb)
{
    int error = OpportunityOfMove(x,y);
    if(error == ERRORS::YES){
        field[x][y] = symb;
    }

    return error;
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
