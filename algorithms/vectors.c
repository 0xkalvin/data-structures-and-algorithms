#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool sameSmallest(int v1[10], int v2[10]){

    int m1 = v1[0];
    int m2 = v2[0];

    for (int i = 0; i < 10; i++)
    {
        if(v1[i] < m1){
            m1 = v1[i];
        }

        if(v2[i] < m2){
            m2 = v2[i];
        }
    }
    
    printf(" %d \n", m1);
    printf(" %d \n", m2);

    return m1 == m2;
}




int main(void){


    int v1[10] = {1,2,3,4,-3,6,7,8,9,10};
    int v2[10] = {1,2,3,4,5,6,7,8,-1,10};

    printf(" %d ", sameSmallest(v1, v2));


}