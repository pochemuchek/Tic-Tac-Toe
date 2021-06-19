#include <QCoreApplication>
#include "player.h"
#include "field.h"

#include "global.h"

#include <iostream>
#include <tuple>

//#define HUMAN_VS_AI
using namespace std;

void game_human_VS_human(FIELD *, PLAYER *, PLAYER *);
void game_human_VS_AI(FIELD *, PLAYER *, PLAYER *);

std::pair<int /*x*/, int /*y*/> GetMove(const char*);
//------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FIELD *field_TicTacToe = new FIELD();

    PLAYER *first = new PLAYER(field_TicTacToe,
                               TYPE_PLAYER::human,
                               SYMBOL::tic);
    PLAYER *second;
#ifdef HUMAN_VS_AI
    second = new PLAYER(field_TicTacToe,
                        TYPE_PLAYER::AI,
                        SYMBOL::tac);
#else
    second = new PLAYER(field_TicTacToe,
                        TYPE_PLAYER::human,
                        SYMBOL::tac);
#endif
    field_TicTacToe->ShowField();
    if(first->type_player == TYPE_PLAYER::human && second->type_player == TYPE_PLAYER::human){
// human vs human
        game_human_VS_human(field_TicTacToe, first, second);
    }
    else if(first->type_player == TYPE_PLAYER::AI || second->type_player == TYPE_PLAYER::AI) {
// human vs AI
        game_human_VS_AI(field_TicTacToe, first, second);
    }

    delete first;
    delete second;
    delete field_TicTacToe;
    cout << "game end" << std::endl;

    return a.exec();
}
//------------------------------------------------------------------------
int MakeMovePlayer(PLAYER* player, FIELD* field, const char* player_name) {
    pair<int,int> coor_move;
    do {
        do {
            coor_move = GetMove(player_name);    //request move from console, and wait while data will not correct
        }
        while (field->isMovePossible(coor_move.first, coor_move.second) == -1);    //check movement is possible or not?
    }
    while (player->MakeMovePL(coor_move.first, coor_move.second, player->type_player, field) != ERRORS::YES);   //make move

//below （下列） maybe function...
    field->ShowField();
    if(field->CheckWinner() == ERRORS::WINNER) {
        return ERRORS::WINNER;   //winner
    }
    return ERRORS::NEXT_MOVE;   //continue play
}
//------------------------------------------------------------------------
/*

    нет возможности выбора хода, всегда первым ходит только первый игрок!!!
*/
void game_human_VS_human(FIELD *field_TicTacToe, PLAYER *first, PLAYER *second) {
    int count_move = 0;
    while(count_move < 9) {
//first player movements
        if (MakeMovePlayer(first, field_TicTacToe, "first player") == ERRORS::WINNER) {
            std::cout << "first winner" << std::endl;
            break;
        }
//second player movements
        if (MakeMovePlayer(second, field_TicTacToe, "second player") == ERRORS::WINNER) {
            std::cout << "second winner" << std::endl;
            break;
        }

        count_move += 2;
    }
}
//------------------------------------------------------------------------
void game_human_VS_AI(FIELD *field_TicTacToe, PLAYER *first, PLAYER *second) {
    int x = 0;
    int y = 0;
    int count = 0;

    while(count < 9) {
        do {
            cout << "player\n";
            cout << "enter x = ";
            cin >> x;
            cout << "enter y = ";
            cin >> y;
            count++;

            if(field_TicTacToe->isMovePossible(x,y) == -1){
                cout << "player\n";
                cout << "enter x = ";
                cin >> x;
                cout << "enter y = ";
                cin >> y;
            }
        }while (first->MakeMovePL(x, y,first->type_player, field_TicTacToe) != ERRORS::YES);
        field_TicTacToe->ShowField();

            if(field_TicTacToe->CheckWinner() == 1){
                break;

            }
         cout<<"AI think..."<<endl;
         cout<<second->MakeMovePL(x,y,second->type_player, field_TicTacToe)<<endl;
         field_TicTacToe->ShowField();

         if(field_TicTacToe->CheckWinner() == 1){
             break;
            }
    }
}
//------------------------------------------------------------------------
/*
 *
 */
std::pair<int /*x*/, int /*y*/> GetMove(const char* player_name) {
    int x = -1, y = -1;
    cout << player_name << endl;
    do {
        cout << "enter x = ";
        cin >> x;
        if (cin.fail()) {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n');
            x = -1;
        }
    }
    while (x == -1);

    do {
        cout << "enter y = ";
        cin >> y;
        if (cin.fail()) {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767,'\n');
            y = -1;
        }
    }
    while (y == -1);

    return make_pair(x,y);
}
//------------------------------------------------------------------------
