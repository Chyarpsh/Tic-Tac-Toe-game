// File Name: GameState.cpp
// Author: Arpita Chowdhury
// Date: 04/30/2024
// Assignment Number: Programming assignment - 4
// Instructor: Xiaomin Li
// CS5301.251 spring 2024
// GameState represents the current state of a tic tac toe game that allows
// players to undo the most recent of their opponents moves.
// It maintains the current game board and a stack of the currently active
// moves in the game.  It can record a move, and undo a move, and it
// can return the number current player (0 or 1), and also determine
// if the player who made the most recent move has won the game.
#include <iostream>
using namespace std;

#include "GameState.h"

//***********************************************************
// checkLastPlayerWin: determines if the player with the most
//   recent move has won the tic tac toe game
// returns true if the last move has won the game, otherwise false.
//***********************************************************
bool GameState::checkLastPlayerWin() {
    char targetSymbol = getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i){
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j){
            sumHorizontal += boardState[i][j] == targetSymbol;
            sumVertical += boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i){
        sumDiagonal1 += boardState[i][i] == targetSymbol;
        sumDiagonal2 += boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

//***********************************************************
// constructor: initializes game board to all '_' underscores.
//***********************************************************
GameState::GameState() {
  for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
          boardState[i][j] = '_';
    }
  }
} 

//***********************************************************
// getCurrentPlayer returns the player that has to make the next turn.
// returns 0 for player 0 and 1 for player 1
//even player 0 turn - x move
//odd player 1 turn - o move
//***********************************************************
int GameState::getCurrentPlayer() {
    return moveStack.getSize() % 2;
}

//***********************************************************
// addMove: given the move of the current player, it updates
// the state of the board and stack of the past moves.
// returns -1 if the turn is invalid (the target position is not empty)
// returns 0 if the move was successful and all positions are filled
// returns 1 if the move was successful and there are moves available,
//***********************************************************
int GameState::addMove(Move move) {
   if(boardState[move.x][move.y] != '_')
       return -1;
   //update board state by pushing a move
   if(getCurrentPlayer() == 0)
       boardState[move.x][move.y] = 'x';
   else
       boardState[move.x][move.y] = 'o';
   //move values using push operation
   moveStack.push(move);
   if(moveStack.getSize() == 9){
      return 0;
   }
     return 1;
}

//***********************************************************
// undoLast: Undoes the last turn by changing the board state to the
//   previous one and removing the last move from the stack.
// returns true if the move was removed, false if there are
//   no moves to undo.
//***********************************************************
bool GameState::undoLast() {
   if (moveStack.getSize() == 0) {
    return false;
  }
  // Pop the last move and update board
  Move lastTurnMove = moveStack.top();
  boardState[lastTurnMove.x][lastTurnMove.y] = '_';
  moveStack.pop();
  return true;
}

//***********************************************************
// displayBoardState: Prints the board state to the "out" stream.
//***********************************************************
void GameState::displayBoardState(std::ostream& out) {
    for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
          out<<boardState[i][j];
    }
    out<<endl;
  }
}
