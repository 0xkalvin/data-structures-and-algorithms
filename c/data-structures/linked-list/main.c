#include "linkedlist.h"



int main(void){

    List* myList = createList();

    int i;

    for(i = 0; i < 5; i++)
        insertAtLast(myList, i);

    
    for(i = 100; i > 95; i--)
        insertAtFirst(myList, i);
    
    
    printList(myList);

    removeFirst(myList);
    removeLast(myList);

    printList(myList);

    printf("Inverting...\n");
    
    myList = invert(myList);

    printList(myList);

    invertHardWay(myList);

    printList(myList);

    return 0;
}