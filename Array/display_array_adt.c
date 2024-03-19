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

void add(struct array *arr, int val)
{
    if(arr->length<arr->size)
    {
    arr->a[arr->length]=val;
    arr->length++;
    }
    else
        printf("Size is full, not possible to add new elements\n");
}

int main()
{
    struct array arr;
    int n, val;
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    arr.length = 0;
    arr.a = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.a[i]);
    arr.length = n;

    display(arr);
    printf("Enter the data you want to add: ");
    scanf("%d",&val);
    add(&arr,val);

    display(arr);
    return 0;
}
