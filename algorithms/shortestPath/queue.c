#include "queue.h"

Node *createNode(int r, int c, int d)
{

    Node *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
        return NULL;

    newNode->row = r;
    newNode->column = c;
    newNode->distance = d;

    return newNode;
}

Queue *createQueue()
{

    Queue *newQueue = (Queue *)malloc(sizeof(Queue));

    if (!newQueue)
        return NULL;

    newQueue->head = NULL;

    printf("AAAAAAAA");

    return newQueue;
}

void enqueue(Queue *q, Node *n)
{
    if (q->head == NULL)
    {
        q->head = n;
    }
    else
    {
        n->next = q->head;
        q->head = n;
    }
}

int isEmpty(Queue* q)
{
    return q->head == NULL;
}

void dequeue(Queue * q)
{
    if (!isEmpty(q))
    {   
        Node* temp = q->head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }

}

void printQueue(Queue* q){
    
    Node* temp = q->head;

    if (temp == NULL)   return;

    printf("[ ");
    while (temp->next != NULL)
    {
        printf("{ { %d, %d }, %d }, ", temp->row, temp->column, temp->distance);
        temp = temp->next;
    }
    printf("{ %d, %d }, %d } ]\n", temp->row, temp->column, temp->distance);
}
