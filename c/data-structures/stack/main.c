#include "stack.h"

int main(void){

    Stack* myStack = createStack();


    for(int i = 0; i < 10; i++) push(myStack, i);


    printStack(myStack);

    pop(myStack);
    
    printStack(myStack);

    printf("Top is %d \n", getTop(myStack));


    return 0;
}

