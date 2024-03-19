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

void reverse(struct array *arr)
{
    int *b = (int *)malloc(arr->length * sizeof(int)),i,j;
    for( i=arr->length-1, j=0;i>=0;i--,j++)
    {
        b[j]=arr->a[i];
    }
    for( i=arr->length-1, j=0;i>=0;i--,j++)
    {
        arr->a[i]=b[i];
    }
}

// better approach

void reverse1(struct array *arr)
{
    int i,j;
    for(int i=0,j=arr->size-1;i<j;i++,j--)
    {
        int temp = arr->a[i];
        arr->a[i]=arr->a[j];
        arr->a[j]=temp;
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

        reverse(&arr);
        display(arr);
        reverse1(&arr);
        display(arr);
    }

    return 0;
}
