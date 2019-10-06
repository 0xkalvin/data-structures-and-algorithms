#include "queue.h"

int main(void){

    Queue* myQueue = createQueue();


    for(int i = 0; i < 10; i++) enqueue(myQueue, i);


    printQueue(myQueue);

    dequeue(myQueue);

    printQueue(myQueue);

    return 0;
}