// Filename MoveStack.cpp
// Author: Arpita Chowdhury
// Date: 04/30/2024
// Assignment Number: Programming assignment - 4
// Instructor: Xiaomin Li
// CS5301.251 spring 2024
// MoveStack A regular stack that stores instances of the Move structure. 
// A Move records the coordinates of the 'x' or 'o' token placed on the game board. 
// All past moves are stored here. The stack is required in order to be able to undo moves.


#include <cassert>
using namespace std;

#include "MoveStack.h"

//****************************************************
// MoveStack: Constructor of class MoveStack which creates a dynamic array and initializes array index topPtr to 0.
// return type: None                 
//****************************************************
MoveStack::MoveStack() { 
  arr = new Move[stack];
  ptr = 0;
}

//****************************************************
// MoveStack: Destructor of class MoveStack which  deletes dynamically created array.
// return type: None                 
//****************************************************
MoveStack::~MoveStack() {
  delete [] arr;
}

//****************************************************
// Member function getsize returns a count of the    *
// number of elements on the stack.                  *
//****************************************************
int MoveStack::getSize() {
    int a = ptr;
    return a;
 }

//****************************************************
// Member function top returns the value at the top  *
// of the stack (does not remove it).                *
//****************************************************
Move MoveStack::top() {
    assert(!isEmpty());
    Move value = arr[ptr];
    return value;
}
//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
// move: the Move item to be pushed               *
//*************************************************
void MoveStack::push(Move move) {
   assert( !isFull());
   ptr++;
   arr[ptr] = move;
};
//****************************************************
// Member function pop removes the value at the top  *
// of the stack, but returns nothing.                *
//****************************************************
void MoveStack::pop() {
    assert(!isEmpty());
    Move num = arr[ptr];
    ptr--;
}

//*****************************************************
// Member function isEmpty returns true if the stack *
 // is empty, or false otherwise. *
 //*****************************************************

 bool MoveStack::isEmpty() const
{
   bool state;
   if (ptr == 0)
      state = true;
  else
      state = false;

   return state;
}

//*****************************************************
// Member function isFull returns true if the stack *
 // is full, or false otherwise. *
 //*****************************************************

 bool MoveStack::isFull() const
{
   bool state;
   if (ptr == stack)
      state = true;
  else
      state = false;

   return state;
}