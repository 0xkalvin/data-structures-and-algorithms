#include <stdio.h>
#include <stdlib.h>

int *merge(int arr1[], int arr2[], int size1, int size2)
{

    int *result = (int *)malloc((size1 + size2) * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2)
    {

        if (arr1[i] >= arr2[j])
        {
            result[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            result[k] = arr1[i];
            i++;
            k++;
        }
    }

    while (i < size1)
    {
        result[k] = arr1[i];
        k++;
        i++;
    }

    while (j < size2)
    {
        result[k] = arr2[j];
        k++;
        j++;
    }

    return result;
}

int main(void)
{

    int arr1[] = {1, 3, 5, 7, 9, 11, 13, 13};
    int arr2[] = {2, 4, 6, 8, 10, 13};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int *p = merge(arr1, arr2, size1, size2);

    for (int i = 0; i < size1 + size2; i++)
    {
        printf(" %d ", p[i]);
    }

    return 0;
}