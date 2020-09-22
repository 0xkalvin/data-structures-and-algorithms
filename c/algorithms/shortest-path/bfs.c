#include <stdbool.h>

#include "queue.h"


/*  Find the shortest distance using breadth-first search    */
int shortestDistance(char grid[4][4], int m, int n)
{   

    Node* source = createNode(0, 0, 0);
    bool visited[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] == '0')
            {
                visited[i][j] = true;
            }
            else
            {
                visited[i][j] = false;
            }

            if (grid[i][j] == 'S')
            {
                source->row = i;
                source->column = j;
            }
        }
    }
    
    Queue* q = createQueue();
    enqueue(q, source);
    
    visited[source->row][source->column] = true;

    while(!isEmpty(q)){

        Node* current = q->head;
        dequeue(q);

        // DESTINATION FOUND
        if(grid[current->row][current->column] == 'D' ){
            return current->distance;
        }

        // MOVING UP
        if(current->row - 1 >= 0 && visited[current->row - 1][current->column] == false){
            
            enqueue(q, createNode(current->row - 1, current->column, current->distance + 1));
            
            visited[current->row - 1][current->column] = true;
        }

        // MOVING DOWN
        if(current->row + 1 < m  && visited[current->row + 1][current->column] == false){
            
            enqueue(q, createNode(current->row + 1, current->column, current->distance + 1));
            
            visited[current->row + 1][current->column] = true;
        }

        // MOVING LEFT
        if(current->column - 1 >= 0 && visited[current->row][current->column - 1] == false){
            
            enqueue(q, createNode(current->row, current->column - 1, current->distance + 1));
            
            visited[current->row][current->column - 1] = true;
        }


        // MOVING RIGHT
        if(current->column + 1 < n && visited[current->row][current->column + 1] == false){
            
            enqueue(q, createNode(current->row, current->column + 1, current->distance + 1));
            
            visited[current->row][current->column + 1] = true;
        }
    }

    return -1;    
}

int main(void)
{   
    char grid[4][4] = {
        {'0', '1', '0', '0'},
        {'1', '1', '1', 'S'},
        {'1', '1', '1', '1'},
        {'D', '1', '1', '1'}
    };

    printf("\n The shortest distance is  %d \n", shortestDistance(grid, 4, 4));

    return 0;
}