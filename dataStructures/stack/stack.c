#include "stack.h"


Stack* createStack(){

    Stack* s = malloc(sizeof(Stack));

    if(s == NULL)   return NULL;

    s->length = 0;

    return s;

}

void push(Stack* s, int data){

    if(!isFull(s)){
        
        s->data[s->length] = data;
        s->length++;
        return;
    }

    printf("Stack Overflow! \n");
}

void pop(Stack* s){

    if(s->length > 0){
        
        s->length--;
        return;
    }

    printf("Stack Underflow \n");
}

int isEmpty(Stack *s){

    return s->length <= 0;
}

int isFull(Stack* s){

    return s->length == STACK_MAX_LENGTH;
}

int getTop(Stack* s){
    
    if(!isEmpty(s))
        return  s->data[s->length - 1];
    
    return -1;
}

void printStack(Stack* s){

    Stack temp = *s;

    printf("[ ");
    while(!isEmpty(&temp)){
        printf("%d, ", getTop(&temp));
        pop(&temp);
    }
    printf("]\n");
}