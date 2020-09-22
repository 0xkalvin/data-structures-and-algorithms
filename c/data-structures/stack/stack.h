#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_LENGTH 100

typedef struct Stack {
    int data[STACK_MAX_LENGTH];
    int length;
} Stack;


Stack* createStack();
void push(Stack* s, int data);
void pop(Stack* s);
int getTop(Stack* s);
void printStack(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);

#endif
