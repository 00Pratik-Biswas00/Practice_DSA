#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

struct array
{
    int size, length, *a;
};

void display(struct array *arr)
{
    for (int i = 0; i < arr->length; i++)
        printf("%d ", arr->a[i]);
    printf("\n");
}

int check_sorted(struct array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->a[i] > arr->a[i + 1])
            return -1;
    }
    return 1;
}

int insert_sorted(struct array *arr, int key)
{
    int i = arr->length - 1;
    while (arr->a[i] > key)
    {
        arr->a[i + 1] = arr->a[i];
        i--;
    }
    arr->a[i + 1] = key;
    arr->length++;
}

int move_negative(struct array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->a[i] < 0)
            i++;
        while (arr->a[j] > 0)
            j--;
        if (i < j)
        {
            int t = arr->a[i];
            arr->a[i] = arr->a[j];
            arr->a[j] = t;
        }
    }
}

int main()
{
    struct array arr;
    arr.size = 100;
    int n;
    scanf("%d", &n);
    arr.length = n;
    arr.a = (int *)malloc(arr.size * sizeof(int));

    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.a[i]);
    display(&arr);

    if (check_sorted(&arr) == 1)
        printf("sorted\n");
    else
        printf("not sorted\n");

    insert_sorted(&arr, 4);
    display(&arr);

    move_negative(&arr);
    display(&arr);

    return 0;
}
