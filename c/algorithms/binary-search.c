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
