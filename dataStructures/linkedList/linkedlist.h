#include <stdio.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;


List* createList();
Node* createNode(int data);
void insertAtLast(List* l, int data);
void insertAtFirst(List* l, int data);
void insertSorted(List* l, int data);
void removeLast(List* l);
void removeFirst(List* l);
void printList(List* l);
List* invert(List* l);
void invertHardWay(List *l);

#endif
