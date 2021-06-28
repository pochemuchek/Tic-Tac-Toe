#ifndef GLOBAL_H
#define GLOBAL_H


enum SYMBOL { //новые типы которые мы придумали, их перечисление
    tic = 'X',
    tac = 'O',
    no = '_',
};

enum ERRORS{
    YES,
    INCORECT_COOR,
    NO_WIN_MOVE,
    WIN,
    NEXT_MOVE,
    NOT_MY_MOVE,
    DRAW,

};

enum TYPE_PLAYER {
    reserved = 0,
    human = 1,
    AI = 2,
};

enum TYPE_GAME{
    HUMAN_VS_HUMAN = 1,
    HUMAN_VS_AI = 2,
};

#endif // GLOBAL_H
