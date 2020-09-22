#include <stdio.h>
#include <stdlib.h>


int getNumberOfCoins(int coins[], int value, int numOfCoins){

    int counter = 0;
    int i = numOfCoins - 1;

    while(value != 0){
        
        if(coins[i] > value){
            i--;
        }
        else {
            printf(" %d ", coins[i]);
            value -= coins[i];
            counter++;
        }
         
    }

    return counter;
}


int main(void){

    int coins[] = {1, 5, 10, 25, 50, 100};
    int numOfCoins = 6;
    int value = 111;



    printf("\n Needs %d coins for change \n", getNumberOfCoins(coins, value, numOfCoins));


    return 0;
}