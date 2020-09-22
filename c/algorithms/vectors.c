#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "binarySearch.c"
#include "sorting/mergeSort.c"

/*  
    So this is an compilation of exercises that involves doing something with 
    an array
*/


/*  Checks if two passed arrays have the same smallest number  */
int sameSmallest(int arr1[10], int arr2[10]){

    int s1 = arr1[0];
    int s2 = arr2[0];

    for (int i = 0; i < 10; i++)
    {
        if(arr1[i] < s1){
            s1 = arr1[i];
        }

        if(arr2[i] < s2){
            s2 = arr2[i];
        }
    }
    
    return s1 == s2;
}


/*  
    returns the smallest number that's in both passed array if there's 
    at least one element in common
 */
int smallestCommon(int arr1[], int arr2[], int size1, int size2){

    /*  sorts first array*/
    mergeSort(arr1, 0, size1 - 1);

    int s = INT_MAX;

    /*  
        For each element in arr2, binary searches it in arr1.
        If found, checks if is less than the others found.
    */
    for(int i = 0; i < size2; i++){

        if(binarySearchRecursive(arr1, 0, 9, arr2[i]) >= 0){
            if(arr2[i] < s){
                s = arr2[i];
            }
        }
    }
    
    return s;
}


int onlyOneSwap(int arr[10]){


    int temp[10];
    for(int i = 0; i < 9; i++){
        temp[i] = arr[i];
    }

    mergeSort(temp, 0, 9);

    int c = 0;
    for(int i = 0; i < 9; i++){

        if(arr[i] != temp[i]){
            c++;
        }

    }
    return c == 2 || c == 0;
}

