#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *a, size, length;
};

void display(struct array arr)
{
    printf("Elements are: ");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.a[i]);
    printf("\n");
}

int linearSearch(struct array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.a[i])
            return i;
    }
    return -1;
}

int main()
{
    struct array arr;
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    arr.length = 0;
    arr.a = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr.length = n;
    if (arr.length > arr.size)
        printf("Length of the array should be lesser than the size of the array\n");
    else
    {
        printf("Enter the data: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr.a[i]);
        display(arr);

        //  ------------------------------------------------

        printf("Enter the data you want to search: ");
        scanf("%d", &key);
        if (linearSearch(arr, key))
            printf("Index of the element is: %d\n", linearSearch(arr, key));
        else
            printf("Element is not found\n");
    }

    return 0;
}
