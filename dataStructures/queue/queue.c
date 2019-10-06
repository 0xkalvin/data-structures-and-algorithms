#include "queue.h"



Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Queue* createQueue(){

    Queue* q = malloc(sizeof(Queue));

    if(q == NULL)   return NULL;

    q->head = NULL;

    return q;
}

void enqueue(Queue* q, int data){
    
    Node* temp = createNode(data);

    if(q->head == NULL) {

        q->head = temp;
        return;
    }

    while(q->head->next != NULL)
        q->head = q->head->next;

    q->head->next = temp;
    
}

void dequeue(Queue* q){

    if(q->head == NULL) return;

    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
}

void printQueue(Queue* q){

    Node* temp = q->head;

    printf("front <- rear \n [ ");

    while(temp->next != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }

    printf("%d ]\n", temp->data);
}