#include "hashtable.h"


HashTableNode* createHashTableNode(char* key, int data){

    HashTableNode* node = (HashTableNode*)malloc(sizeof(HashTableNode));

    if(node == NULL)    return NULL;

    node->data = data;
    node->key = key;
    node->next = NULL;

    return node;
}

HashTable* createHashTable(int c){

    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    
    if(ht == NULL)   NULL;
    
    ht->capacity = c;
    ht->table = (HashTableNode**)malloc(c * sizeof(HashTable*));
    for(int i = 0; i < c; i++)  ht->table[i] = NULL;
    
    return ht;
}

void store(HashTable* ht, char* key, int data, int size){

    int index = hash(ht, key, size);

    if(index >= ht->capacity){
        printf("\nInvalid key! \n");
        return;
    }

    if(ht->table[index] == NULL){

        ht->table[index] = createHashTableNode(key, data);
    }
    else {

        HashTableNode* temp = ht->table[index];

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = createHashTableNode(key, data);

    } 
}

int fetch(HashTable* ht, char* key, int size){


    int index = hash(ht, key, size);


    if(!ht->table[index]){
        printf("\n There's no such key on the table! \n");
        return -1;
    }

    HashTableNode* temp = ht->table[index];
    
    while(temp != NULL || temp->key != key){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\n There's no such key on the table! \n");
        return -1;
    }

    return temp->data;
}


int hash(HashTable* ht,char *key, int size){

    int hash = 0;
    
    for(int i = 0; i < size; i++){
        printf("\n key[%d] -> %2d", i, key[i]);
        hash = hash + (i * key[i]);
    }

    return hash % 97;
}