#include <stdio.h>
#include <stdlib.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct HashTableNode {
    struct HashTableNode* next;
    char* key;
    int data;
}   HashTableNode;


typedef struct HashTable {
    HashTableNode** table;
    int capacity;
} HashTable;


HashTableNode* createHashTableNode(char* key, int data);
HashTable* createHashTable(int capacity);
void store(HashTable* ht, char* key, int data, int size);
int fetch(HashTable* ht, char* key, int size);
int hash(HashTable* ht, char* key, int size);


#endif