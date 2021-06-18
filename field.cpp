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
    field = new int *[h];//выделяем новый столбик длинной h

    //и в этом столбике у каждого элемента ссылка остается на строку от этого столба
    for(int i = 0; i < h; i++){
        field[i] = new int [w];
        for (int j = 0; j < w; j++){
            field[i][j] = SYMBOL::no;
        }
    }
}

FIELD::~FIELD()
{
    for(int i = 0; i < h ; i++){
        delete [] field[i];
    }
    delete [] field;
}

int FIELD::OpportunityOfMove(int x, int y){
    if(x > w || y > h){
        return -1;
    }
    if(field[x][y] != SYMBOL::no ){
        return -1;
    }
    else{
        return 1;
    }
}

int FIELD::MakeMoveF(int x, int y, char symb)
{
    if(FIELD::OpportunityOfMove(x,y) == 1){
        field[x][y] = symb;
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
            cout << (char)field[x][y] << "|";
        }
        cout << endl;
    }
    cout << endl;
}

int FIELD::CheakWinner()
{
    if(CheakWinHorizontal() == true){
    O_count = 0;
    X_count = 0;
    return 1;
    }
    if(CheakWinVertical() == true){
    O_count = 0;
    X_count = 0;
    return 1;
    }
    if(CheakWinDiagLeft() == true){
    O_count = 0;
    X_count = 0;
    return 1;
    }
    if(CheakWinDiagRight() == true){
    O_count = 0;
    X_count = 0;
    return 1;
    }
    return -1;
}

bool FIELD::CheakWinVertical()
{
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(field[i][j] == SYMBOL::tac && field[i][j] != SYMBOL::no){
                O_count++;
            }
            else if(field[i][j] == SYMBOL::tic && field[i][j] != SYMBOL::no){
                X_count++;
            }

            if(O_count == w){
                cout<<"(0)-is winv"<< endl;
                return true;
            }else if(X_count == w){
                cout<<"(X)-is winv"<< endl;
                return true;
            }
        }
        O_count = 0;
        X_count = 0;
    }
    return false;
}

bool FIELD::CheakWinHorizontal()
{
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(field[j][i] == SYMBOL::tac && field[j][i] != SYMBOL::no){
                O_count++;
            }
            else if(field[j][i] == SYMBOL::tic && field[j][i] != SYMBOL::no){
                X_count++;
            }

            if(O_count == w){
                cout<<"(0)-is winh"<< endl;
                return true;
            }else if(X_count == w){
                cout<<"(X)-is winh"<< endl;
                return true;
            }
        }
        O_count = 0;
        X_count = 0;
    }
    return false;
}

bool FIELD::CheakWinDiagLeft()
{
    for(int i = 0; i < w; i++){
        if(field[i][i] == SYMBOL::tac && field[i][i] != SYMBOL::no){
            O_count++;
        }
        else if(field[i][i] == SYMBOL::tic && field[i][i] != SYMBOL::no){
            X_count++;
        }
        if(O_count == w){
            cout<<"(0)-is windl"<< endl;
            return true;
        }else if(X_count == w){
            cout<<"(X)-is windl"<< endl;
            return true;
        }
    }
    O_count = 0;
    X_count = 0;
    return false;
}

bool FIELD::CheakWinDiagRight()
{
    for(int i = w - 1; i >= 0; i--){
        for(int j = 0; j < h; j++){
            if(field[i][j] == SYMBOL::tac && field[i][j] != SYMBOL::no){
                O_count++;
            }
            else if(field[i][j] == SYMBOL::tic && field[i][j] != SYMBOL::no){
                X_count++;
            }

            if(O_count == (1 + w)){
                cout<<"(0)-is windr"<< endl;
                return true;
            }else if(X_count ==(1 + w)){
                cout<<"(X)-is windr"<< endl;
                return true;
            }
        }
    }
    O_count = 0;
    X_count = 0;
    return false;
}

