#include <stdio.h>
#include <math.h>

/*

    p(n) = (2 ^ n) - 1

    Base case
        n = 1       ->  p(1) = (2 ^ 1) - 1 = 1

    Assuming that 
        n = k       ->  p(k) = (2 ^ k) - 1 is true.

    Now let's find
        n = k + 1   ->  p(k + 1) = (2 ^ k + 1) - 1
                        p(k + 1) = 2 * p(k) + 1
                        p(k + 1) = 2 * ((2 ^ k) - 1) + 1
                        p(k + 1) = (2 ^ k + 1) - 2 + 1
                        p(k + 1) = (2 ^ k + 1) - 1
    
    By induction, the minimum number of moves for n disks is (2 ^ n) - 1 

*/
void towerOfHanoi(int numberOfDisks, char origin, char temp, char destiny)
{

    if (numberOfDisks == 1)
    {
        printf("\t\tMove disk %d from origin %c to destiny %c \n", numberOfDisks, origin, destiny);
        return;
    }
    else
    {

        towerOfHanoi(numberOfDisks - 1, origin, destiny, temp);

        printf("\t\tMove disk %d from origin %c to destiny %c \n", numberOfDisks, origin, destiny);

        towerOfHanoi(numberOfDisks - 1, temp, origin, destiny);
    }
}

int main(void)
{

    char origin = 'A';
    char temp = 'B';
    char destiny = 'C';
    int numberOfDisks = 3;

    printf("\t\t Tower of Hanoi \n\n");

    towerOfHanoi(numberOfDisks, origin, temp, destiny);

    int numberOfMoves = pow(3, 2) - 1;
    printf("\n\t\t Number of disks: %d \n", numberOfDisks);
    printf("\t\t Number of required moves: %d \n\n", numberOfMoves);

    return 0;
}
