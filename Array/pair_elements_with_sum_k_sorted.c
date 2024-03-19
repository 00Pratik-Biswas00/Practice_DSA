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

void pairElementsSorted(struct array arr, int key)
{
    int l = arr.a[0], h = arr.a[arr.length - 1];
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (l < h)
        {
            if ((l + h) == key)
            {
                printf("(%d,%d)\n", l, h);
                l++;
                h--;
            }
            else  if((l+h)<key)
            {
                l++;
            }
            else
                h--;
        }
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

    int key; scanf("%d",&key);

    pairElementsSorted(arr,key);

    return 0;
}
