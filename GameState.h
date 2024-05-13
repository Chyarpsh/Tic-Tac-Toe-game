//  File name: MoveStack.h
//  Author : Arpita Chowdhury
// Date: 04/30/2024
// Assignment Number: Programming assignment - 4
// CS5301.251 spring 2024
//Specification file for GameState class which includes preprocesor directives of respsective class and this header file is included in other .cpp files


#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>
#include "MoveStack.h"


class GameState {
    char boardState[3][3];
    MoveStack moveStack;
public:
    GameState();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out);
    bool checkLastPlayerWin();
};


#endif //GAMESTATE_H
