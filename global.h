#ifndef GLOBAL_H
#define GLOBAL_H


enum SYMBOL { //новые типы которые мы придумали, их перечисление
    tic = 'X',
    tac = 'O',
    no = '_',
};

enum ERRORS{
    YES,
    NO_WIN_MOVE,
    WIN,
    NOT_MY_MOVE,
    DRAW,

};

enum TYPE_PLAYER {
    reserved = 0,
    human = 1,
    AI = 2,
};
#endif // GLOBAL_H
