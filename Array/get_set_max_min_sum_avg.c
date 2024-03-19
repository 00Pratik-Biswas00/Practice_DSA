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

// get

int get(struct array arr, int index)
{
    if (index >= 0 && index <= arr.length - 1)
        return arr.a[index];
    return -1;
}

// set

int set(struct array *arr, int index, int key)
{
    if (index >= 0 && index <= arr->length - 1)
        arr->a[index] = key;
    return -1;
}

// max

int max(struct array arr)
{
    int max = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.a[i] > max)
            max = arr.a[i];
    }
    return max;
}

// min

int min(struct array arr)
{
    int min = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.a[i] < min)
            min = arr.a[i];
    }
    return min;
}

// sum

int sum(struct array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.a[i];
    }
    return sum;
}

int sum1(struct array arr, int n)
{
    if (n < 0)
        return 0;
    return sum1(arr, n - 1) + arr.a[n];
}

// avg

int avg(struct array arr,int n)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.a[i];
    }
    return sum/n;
}

int main()
{
    struct array arr;
    int n, ind;
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

        printf("Enter the index: ");
        scanf("%d", &ind);

        // get

        //        if (get(arr, ind))
        //            printf("Index at that element is: %d\n", get(arr, ind));
        //        else
        //            printf("Index is not found\n");

        // set

        //        set(&arr,ind,10);
        //        display(arr);

        // max

        //    printf("max element is: %d\n", max(arr));

        // min

        //    printf("min element is: %d\n", min(arr));

        // sum

        //printf("sum of the elements is: %d\n", sum(arr));
        //printf("sum of the elements is: %d\n", sum1(arr, arr.length - 1));

        // avg

        //printf("avg of the elements is: %d\n", avg(arr, arr.length - 1));
    }

    return 0;
}
