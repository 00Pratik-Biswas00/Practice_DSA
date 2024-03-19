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

void findMultipleMissingElement(struct array *arr)
{
    int l = arr->a[0], h = arr->a[arr->length - 1], diff = l - 0;
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->a[i] - i != diff)
        {
            while(diff < arr->a[i]-i)
            {
            printf("missing element: %d\n", i + diff);
            diff++;
            }
        }
    }
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

        findMultipleMissingElement(&arr);
    }

    return 0;
}
