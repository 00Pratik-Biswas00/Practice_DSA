#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

struct array
{
    int *a, size, length;
};

void display(struct array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.a[i]);
    }
    printf("\n");
}

void find_pair(struct array arr, int n, int key) // O(n2)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr.a[i] + arr.a[j] == key)
            {
                printf("(%d+%d)=%d.\n", arr.a[i], arr.a[j], key);
            }
        }
    }
}

int max(struct array arr)
{
    int max = arr.a[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (max < arr.a[i])
            max = arr.a[i];
    }
    return max;
}

void hash_pair(struct array arr, int key) // O(n)
{
    int h = max(arr);
    int k[h];
    for (int i = 0; i <= h; i++)
        k[i] = 0;

    for (int i = 0; i < arr.length; i++)
    {
        if (k[key - arr.a[i]] != 0)
        {
            printf("%d+%d -> %d.\n", arr.a[i], key - arr.a[i], key);
        }
        k[arr.a[i]]++;
    }
}

int main()
{
    struct array arr;
    arr.size = 100;
    int n, key;
    scanf("%d", &n);
    arr.length = n;
    arr.a = (int *)malloc(arr.size * sizeof(int));

    for (int i = 0; i < arr.length; i++)
        scanf("%d", &arr.a[i]);

    display(arr);
    scanf("%d", &key);

    // find_pair(arr,arr.length,key);
    hash_pair(arr, key);
    return 0;
}