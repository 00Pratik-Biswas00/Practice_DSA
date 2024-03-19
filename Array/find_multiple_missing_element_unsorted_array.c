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

void findMissingElementUnsorted(struct array arr)
{
    int l = 1, h = max(arr);

    int k[h];   // creating the hashtable of size max element of the given array
    for(int i = 0; i< h; i++)
    {
        k[i]=0;             // declare the array element as 0
    }
// match the given array element with the index of k and make the value 1
    for (int i = 0; i < arr.length; i++) 
        k[arr.a[i]]++;

// index with 0 is the answer  
    for(int i = l; i<=h;i++)
    {
        if(k[i]==0)
            printf("missing element: %d\n", i);
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
        //display(arr);

        //  ------------------------------------------------

        findMissingElementUnsorted(arr);
    }

    return 0;
}
