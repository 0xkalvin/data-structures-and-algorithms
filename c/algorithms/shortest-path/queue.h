#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int row;
    int column;
    int distance;
    struct Node* next;
} Node;


typedef struct Queue {
    Node* head;

} Queue;

Node* createNode(int r, int c, int d);
Queue* createQueue();
void enqueue(Queue* q, Node* n);
void dequeue(Queue* q);
void printQueue(Queue* q);
int isEmpty(Queue* q);


#endif