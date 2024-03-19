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

void find_duplicates(struct array arr, int n) // O(n2)
{
    int count;
    for (int i = 0; i < n - 1; i++)
    {
        count = 1;
        if (arr.a[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr.a[i] == arr.a[j])
                {
                    count++;
                    arr.a[j] = -1;
                }
            }
        }
        if (count > 1)
            printf("%d appears %d times.", arr.a[i], count);
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

void hash_duplicates(struct array arr)  //O(n)
{
    int h = max(arr);
    int k[h];
    for (int i = 0; i <= h; i++)
        k[i] = 0;

    for (int i = 0; i < arr.length; i++)
        k[arr.a[i]]++;

    for (int i = 0; i <= h; i++)
    {
        if (k[i] > 1)
        {
            printf("%d appears %d times\n", i, k[i]);
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

    for (int i = 0; i < arr.length; i++)
        scanf("%d", &arr.a[i]);

    display(arr);

    // find_duplicates(arr, n);

    hash_duplicates(arr);

    return 0;
}