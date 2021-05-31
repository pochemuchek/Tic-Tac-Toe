#include "field.h"
#include <cstdlib>
#include <iostream>

int count = 0;
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
        cout<<"chose corect coor"<<endl;
        system("pause");    //это не надо
        return -1;
    }
    if(field[x][y] != SYMBOL::no ){
        cout<<"Place are closed"<<endl;
        system("pause");    //это тоже не надо..., обычно это вызывает некоторый ступор, что с этим делать?, и лучше cout из этого метода вынести в другое место
                    //блюдём концепцию, функция должна делать что-то одно, либо выводить информацию на экран, либо ...
                // если так оставить, потом будет сложно навешивать GUI
        return -1;
    }
    else{
        return 1;
    }
}

int FIELD::MakeMove(int x, int y, char symb)
{
    if(FIELD::OpportunityOfMove(x,y) == 1){
        field[x][y] = symb;
        count++;
        //return ERRORS::YES;
    }
    else{
         return -1;
    }
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
//это две переменные самое большое зло!!!... убери их в класс
int X_count = 0;
int O_count = 0;

int FIELD::CheakWinner()
{
    if(CheakWinHorizontal() == true){
//вот такое выравнивание надо делать....
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

    //если функция доберётся до этой строчки то, что будет возращать?? надо return
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
                cout<<"(0)-is win"<< endl;
                system("pause");
                return true;
            }else if(X_count == w){
                cout<<"(X)-is win"<< endl;
                system("pause");
                return true;
            }
        }
        O_count = 0;
        X_count = 0;
        return false; //в этом мест второй цикл выполняться не будет!!!!
    }
    //аналогично предыдущему комментарию
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
                cout<<"(0)-is win"<< endl;
                system("pause");
                return true;
            }else if(X_count == w){
                cout<<"(X)-is win"<< endl;
                system("pause");
                return true;
            }
        }
        O_count = 0;
        X_count = 0;
        return false;   //внешний цикл не выполняется...
    }
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
            cout<<"(0)-is win"<< endl;
            system("pause");
            return true;
        }else if(X_count == w){
            cout<<"(X)-is win"<< endl;
            system("pause");
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

            if(O_count == w){
                cout<<"(0)-is win"<< endl;
                system("pause");
                return true;
            }else if(X_count == w){
                cout<<"(X)-is win"<< endl;
                system("pause");
                return true;
            }
        }
    }
    O_count = 0;
    X_count = 0;
    return false;
}
