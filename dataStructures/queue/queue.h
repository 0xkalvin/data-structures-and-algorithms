#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct Queue {
    Node* head;

} Queue;

Node* createNode(int data);
Queue* createQueue();
void enqueue(Queue* q, int data);
void dequeue(Queue* q);
int isEmpty(Queue* q);
void printQueue(Queue* q);


#endif