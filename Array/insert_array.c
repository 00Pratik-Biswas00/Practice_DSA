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

void insert(struct array *arr, int index, int val)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
            arr->a[i] = arr->a[i - 1];
        arr->a[index] = val;
        arr->length++;
    }
    else
        printf("insertion not possible\n");
}

int main()
{
    struct array arr;
    int n, index, val;
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

        printf("Enter the index & data you want to add: ");
        scanf("%d %d", &index, &val);
        insert(&arr, index, val);

        display(arr);
    }

    return 0;
}
