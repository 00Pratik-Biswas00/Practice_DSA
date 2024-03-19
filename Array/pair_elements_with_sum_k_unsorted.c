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

// iterative way

void pairElementsUnsorted(struct array arr, int key)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.a[i] + arr.a[j] == key)
                printf("(%d,%d)\n", arr.a[i], arr.a[j]);
        }
    }
}

// hashing

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

void pairElementsUnsortedHashing(struct array arr, int key)
{
    int h = max(arr);
    int H[h];
    for (int i = 0; i <= h; i++)
        H[i] = 0;

    for (int i = 0; i < arr.length; i++)
    {
        if (H[key - arr.a[i]] == 1)
            printf("(%d,%d)\n", arr.a[i], key - arr.a[i]);
        H[arr.a[i]] = 1;
    }
}

int main()
{
    struct array arr;
    int n;
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
        // display(arr);

        //  ------------------------------------------------
    }

    int key;
    scanf("%d", &key);

    pairElementsUnsorted(arr, key);
    pairElementsUnsortedHashing(arr, key);
    return 0;
}
