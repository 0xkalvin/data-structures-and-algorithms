#include "hashtable.h"


int hash(char *key, int size){

    int hash = 0;
    
    for(int i = 0; i < size; i++){
        printf("\n key[%d] -> %2d", i, key[i]);
        hash = hash + (i*key[i]);
    }

    return hash;
}