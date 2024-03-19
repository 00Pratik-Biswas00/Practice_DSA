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

void delete(struct array *arr, int index)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i <arr->length-1; i++)
            arr->a[i] = arr->a[i + 1];
        arr->length--;
    }
    else
        printf("deletion is not possible\n");
}

int main()
{
    struct array arr;
    int n, index;
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

        printf("Enter the index you want to delete: ");
        scanf("%d", &index);
        delete(&arr, index);

        display(arr);
    }

    return 0;
}
