#include "hashtable.h"


int main(void){

    HashTable* myTable = createHashTable(50);

    char* bob = "Bob";
    char* alice = "Alice";


    store(myTable, bob, 100, 3);
    store(myTable, alice, 101, 5);


    printf("\n %d   \n", fetch(myTable, alice, 5));


    return 0;
}