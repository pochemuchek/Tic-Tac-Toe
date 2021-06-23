#include "GamePlay.h"

GamePlay::GamePlay(int TypeFirstPl, int TypeSecondPl)
{
    FIELD *field_TicTacToe = new FIELD();
    if(TypeFirstPl == TYPE_PLAYER::human && TypeSecondPl == TYPE_PLAYER::human){//human VS human
        PLAYER *first = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::human,
                                   SYMBOL::tic);

        PLAYER *second = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::human,
                                   SYMBOL::tac);
        field_TicTacToe->ShowField();
        Game_Human_VS_Human(field_TicTacToe, first, second);
    }
    else if(TypeFirstPl == TYPE_PLAYER::AI || TypeSecondPl == TYPE_PLAYER::AI){//human VS AI
        PLAYER *first = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::human,
                                   SYMBOL::tic);

        PLAYER *second = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::AI,
                                   SYMBOL::tac);
        field_TicTacToe->ShowField();
        Game_Human_VS_Ai(field_TicTacToe, first, second);
    }
}

GamePlay::~GamePlay(){
    delete first;
    delete second;
    delete field;
}

std::pair<int,int> GamePlay::GetMove(char *NamePlayer){
    std::pair <int, int> pair;
    cout << NamePlayer <<endl;
    cout << "enter x = ";
    cin >> pair.first;
    cout << "enter y = ";
    cin >> pair.second;

    return pair;
}

int GamePlay::MakeMovePlayer(FIELD *field, PLAYER *player, char *NamePlayer)
{
    std::pair<int, int> coor_move;
    do{
        do{
           coor_move = GetMove(NamePlayer);
        }
        while(field->OpportunityOfMove(coor_move.first, coor_move.second) == ERRORS::INCORECT_COOR);
    }
    while(player->MakeMovePL(coor_move.first, coor_move.second, player->type_player, field) != ERRORS::YES);
    field->ShowField();

    if(VadimArbitr->CheakWinner(field) == ERRORS::WIN){
        return ERRORS::WIN;
    }
    else{
        return ERRORS::NEXT_MOVE;
    }
}

int GamePlay::MakeMoveAI(FIELD *field, PLAYER *player, char *NamePlayer)
{
    player->MakeMovePL(1,1,player->type_player, field);
    field->ShowField();

    if(VadimArbitr->CheakWinner(field) == ERRORS::WIN){
        return ERRORS::WIN;
    }
    else {
        return ERRORS::NEXT_MOVE;
    }
}

void GamePlay::Game_Human_VS_Ai(FIELD *field, PLAYER *first, PLAYER *second)
{
    do{
        if(MakeMovePlayer(field, first, "player") == ERRORS::WIN){
            cout<< "player win" << endl;
            break;
        }
        if(MakeMoveAI(field, second, "second player") == ERRORS::WIN){
            cout<< "AI win" << endl;
            break;
        }

        count_move +=2;
    }while(count_move < 9);
}

void GamePlay::Game_Human_VS_Human(FIELD *field, PLAYER *first, PLAYER *second){
    count_move = 0;
    do{
        if(MakeMovePlayer(field, first, "first player") == ERRORS::WIN){
            cout<< "first player win" << endl;
            break;
        }
        if(MakeMovePlayer(field, second, "second player") == ERRORS::WIN){
            cout<< "Second player win" << endl;
            break;
        }

        count_move +=2;
    }while(count_move < 9);
    cout << "game end"<<endl;
}

