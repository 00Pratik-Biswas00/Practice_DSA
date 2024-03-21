#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[], int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int t;
        printf("Find the answer in pass %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Array before sorting: \n");
    printArray(arr, n);
    printf("\nArray after sorting: \n");
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}