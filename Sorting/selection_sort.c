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
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int indexMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexMin])
                indexMin = j;
        }
        swap(&arr[i], &arr[indexMin]);
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
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}