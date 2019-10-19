#include <stdio.h>
#include <stdlib.h>


int binarySearchRecursive(int array[], int left, int right, int n){

    if(left <= right){

        int mid = (left + right)/2;

        if(n == array[mid]) return mid;
        
        else if(n > array[mid]) return binarySearchRecursive(array, mid + 1, right, n);

        else    return binarySearchRecursive(array, left, mid - 1, n);
    }
    
    return -1;
}

int binarySearchIterative(int array[], int left, int right, int n){

    while(left <= right){

        int mid = (left + right)/2;

        if(n == array[mid]) return mid;

        else if(n > array[mid]) left = mid + 1;

        else right = mid - 1;        
    }

    return -1;

}

int main(void){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 6;

    printf("\n RECURSIVE SOLUTION \n");

    if(binarySearchRecursive(arr, 0, 8, n) >= 0)
        printf("\t%d is at position %d.  \n", n, binarySearchRecursive(arr, 0, 8, n));
    
    else    printf("\t%d is not in array. \n", n);


    printf("\n ITERATIVE SOLUTION \n");

    if(binarySearchIterative(arr, 0, 8, n) >= 0)
        printf("\t%d is at position %d.  \n", n, binarySearchIterative(arr, 0, 8, n));
    
    else    printf("\t%d is not in array. \n", n);

    
    return 0;
}