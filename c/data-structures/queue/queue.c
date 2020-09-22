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

int isEmpty(Queue* q){
    return q->head == NULL;
}

void enqueue(Queue* q, int data){
    

    if(isEmpty(q)) {

        q->head = createNode(data);
        return;
    }

    Node* temp = q->head;

    while(temp->next != NULL)
        temp= temp->next;

    temp->next = createNode(data);
    
}

void dequeue(Queue* q){

    if(isEmpty(q)) return;

    if(q->head->next == NULL){
        q->head = NULL;
        return;
    }

    Node* temp = q->head;
    q->head = q->head->next;
    free(temp);
}

void printQueue(Queue* q){

    Node* temp = q->head;

    if(temp == NULL)   {
        printf("Queue is empty! \n");
        return;
    }

    printf("[ ");
    while(temp->next != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }

    printf("%d ]\n", temp->data);
}