#include "GamePlay.h"
GamePlay::GamePlay(int TypeFirstPl, int TypeSecondPl, ARBITR* arb)
{
    count_move = 0;
    VadimArbitr = arb;
    field_TicTacToe = new FIELD();


    if(TypeFirstPl == TYPE_PLAYER::human && TypeSecondPl == TYPE_PLAYER::human){//human VS human
        first = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::human,
                                   SYMBOL::tic);

        second = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::human,
                                   SYMBOL::tac);
    }
    else if(TypeFirstPl == TYPE_PLAYER::AI || TypeSecondPl == TYPE_PLAYER::AI){//human VS AI
        first = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::human,
                                   SYMBOL::tic);

        second = new PLAYER(field_TicTacToe,
                                   TYPE_PLAYER::AI,
                                   SYMBOL::tac);
    }
}

GamePlay::~GamePlay(){
    delete first;
    delete second;
    delete field_TicTacToe;
}

void GamePlay::StartGame(int TypeGame)
{
    if(TypeGame == TYPE_GAME::HUMAN_VS_HUMAN){
        field_TicTacToe->ShowField();
        Game_Human_VS_Human(first, second);
    }
    else if(TypeGame == TYPE_GAME::HUMAN_VS_AI){
        field_TicTacToe->ShowField();
        Game_Human_VS_Ai(first, second);
    }
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

int GamePlay::MakeMovePlayer(PLAYER *player, char *NamePlayer)
{
    if (field_TicTacToe->getCount_move() == 9) {
        return ERRORS::NOT_POSSIBLE_MOVE;
    }
    std::pair<int, int> coor_move;
    int error = ERRORS::YES;
    do {
        if (error == ERRORS::NOT_POSSIBLE_MOVE) {
            return ERRORS::NEXT_MOVE;
        }
        coor_move = GetMove(NamePlayer);
        error = player->MakeMovePL(coor_move.first, coor_move.second, player->type_player, field_TicTacToe);
    }while (error != ERRORS::YES);
    field_TicTacToe->ShowField();
    return VadimArbitr->CheckWinner(field_TicTacToe);

}

int GamePlay::MakeMoveAI(PLAYER *player)
{
    player->MakeMovePL(1, 1, player->type_player, field_TicTacToe);
    field_TicTacToe->ShowField();

    if(VadimArbitr->CheckWinner(field_TicTacToe) == ERRORS::WIN){
        return ERRORS::WIN;
    }

    return ERRORS::NEXT_MOVE;
}

void GamePlay::Game_Human_VS_Ai(PLAYER *first, PLAYER *second)
{
    count_move = 0;
    do{
        if(MakeMovePlayer(first, "player") == ERRORS::WIN){
            cout<< "player win" << endl;
            break;
        }
        if(MakeMoveAI(second) == ERRORS::WIN){
            cout<< "AI win" << endl;
            break;
        }

        count_move +=2;
    }while(count_move <= 8);
}

void GamePlay::Game_Human_VS_Human(PLAYER *first, PLAYER *second)
{
    count_move = 0;
    do{
        if(MakeMovePlayer(first, "first player") == ERRORS::WIN){
            cout<< "first player win" << endl;
            break;
        }
        if(MakeMovePlayer(second, "second player") == ERRORS::WIN){
            cout<< "Second player win" << endl;
            break;
        }

        count_move +=2;
    }while(count_move <= 8);
}

int GamePlay::EndGame()
{
   int restart = 0;
    cout << "game end"<<endl;
    cout << "Pres '1' to Restart game"<<endl;
    cin >> restart;
    return restart;
}

