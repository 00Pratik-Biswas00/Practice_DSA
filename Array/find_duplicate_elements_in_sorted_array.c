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

// using hashing

void duplicateElementsHash(struct array arr)
{
    int h = max(arr);

    int k[h]; // creating the hashtable of size max element of the given array
    for (int i = 0; i <= h; i++)
    {
        k[i] = 0; // declare the array element as 0
    }


    // match the given array element with the index of k and make the value 1
    for (int i = 0; i < arr.length; i++)
        k[arr.a[i]]++;


    // index with 0 is the answer
    for (int i = 0; i <= h; i++)
    {
        if (k[i] > 1)
            printf("%d appears %d times\n", i, k[i]);
    }
}

// iterative way

void duplicateElements(struct array arr)
{
    int i,j;
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.a[i]==arr.a[i+1])
        {
            j=i+1;
            while(arr.a[i]==arr.a[j])
                j++;
            printf("%d appears %d of times\n", arr.a[i], j-i);
            i=j-1;
        }
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
        // display(arr);

        //  ------------------------------------------------

        duplicateElementsHash(arr);

        //duplicateElements(arr);
    }

    return 0;
}
