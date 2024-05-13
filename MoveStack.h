//  File name: MoveStack.h
//  Author : Arpita Chowdhury
// Date: 04/30/2024
// Assignment Number: Programming assignment - 4
// CS5301.251 spring 2024
//Specification file for MoveStack class which includes preprocessor directives of respective class and this header file is included in other .cpp files

#ifndef MOVESTACK_H
#define MOVESTACK_H

struct Move
{
    int x;
    int y;
    Move(){ x=0; y=0; }
    Move(int a, int b) { x=a, y=b;}
};

class MoveStack
{
private:
    // define variables used to create stack 
    static const int stack  = 15; // The stack size
    int ptr; 
    Move *arr; //pointer to stack array
    bool isEmpty() const;
    bool isFull() const;
      
public:
    MoveStack();
    ~MoveStack();
    int getSize();
    Move top();
    void push(Move move);
    void pop();
};

#endif //MOVESTACK_H