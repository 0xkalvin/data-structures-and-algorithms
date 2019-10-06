#include "stack.h"

int main(void){

    Stack* myStack = createStack();


    for(int i = 0; i < 10; i++) push(myStack, i);


    printStack(myStack);

    //printf("%d \n", myStack->length);

    pop(myStack);

    printf("Top is %d ", getTop(myStack));

    //printStack(myStack);

    return 0;
}

