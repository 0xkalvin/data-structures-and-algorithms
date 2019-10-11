#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../linkedlist/linkedlist.h"

typedef struct HashTableNode {
    List* list;
    char* key;
    int data;
}   HashTableNode;


typedef struct HashTable {
    HashTableNode** table;
    int capacity;
} HashTable;


HashTable* createHashTable(int capacity);
void store(char* key, int data, int size);
void fetch(char* key, int size);
int hash(char* key, int size);


#endif