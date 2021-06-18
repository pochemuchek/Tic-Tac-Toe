#include <QCoreApplication>
#include "player.h"
#include "field.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FIELD *field_TicTacToe = new FIELD();
    PLAYER *first = new PLAYER(field_TicTacToe,
                               TYPE_PLAYER::human,
                               SYMBOL::tic);

    PLAYER *second = new PLAYER(field_TicTacToe,
                               TYPE_PLAYER::AI,
                               SYMBOL::tac);
    field_TicTacToe->ShowField();

    int x = 0;
    int y = 0;
    int count = 0;

    if(first->type_player == TYPE_PLAYER::human &&
       second->type_player == TYPE_PLAYER::human){
    while(count < 9) {
        do {
            cout << "first player\n";
            cout << "enter x = ";
            cin >> x;
            cout << "enter y = ";
            cin >> y;
            count++;

            if(field_TicTacToe->OpportunityOfMove(x,y) == -1){
            cout << "first player\n";
            cout << "enter x = ";
            cin >> x;
            cout << "enter y = ";
            cin >> y;
            }
        }while (first->MakeMovePL(x, y,first->type_player) != ERRORS::YES);
        field_TicTacToe->ShowField();
            if(field_TicTacToe->CheakWinner() == 1){
                break;
            }
        do {
            cout << "second player\n";
            cout << "enter x = ";
            cin >> x;
            cout << "enter y = ";
            cin >> y;
            count++;
            if(field_TicTacToe->OpportunityOfMove(x,y) == -1){
                cout << "second player\n";
                cout << "enter x = ";
                cin >> x;
                cout << "enter y = ";
                cin >> y;
            }
        }
         while (second->MakeMovePL(x, y, second->type_player) != ERRORS::YES);
         field_TicTacToe->ShowField();
            if(field_TicTacToe->CheakWinner() == 1){
                break;
         }
    }
    }

    if(first->type_player == TYPE_PLAYER::AI ||
       second->type_player == TYPE_PLAYER::AI){
        while(count < 9) {
            do {
                cout << "player\n";
                cout << "enter x = ";
                cin >> x;
                cout << "enter y = ";
                cin >> y;
                count++;

                if(field_TicTacToe->OpportunityOfMove(x,y) == -1){
                    cout << "player\n";
                    cout << "enter x = ";
                    cin >> x;
                    cout << "enter y = ";
                    cin >> y;
                }
            }while (first->MakeMovePL(x, y,first->type_player) != ERRORS::YES);
            field_TicTacToe->ShowField();

                if(field_TicTacToe->CheakWinner() == 1){
                    break;

                }
             cout<<"AI think..."<<endl;
             cout<<second->MakeMovePL(x,y,second->type_player)<<endl;
             system("pause");
             field_TicTacToe->ShowField();

             if(field_TicTacToe->CheakWinner() == 1){
                 break;
                }
        }
    }

    delete first;
    delete second;
    delete field_TicTacToe;
    cout<<"game end";


    return a.exec();
}
