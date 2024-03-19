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

void reverse(struct array arr)
{
    for(int i=0,j=arr.length-1;i<j;i++,j--)
    {
        int t=arr.a[i];
        arr.a[i]=arr.a[j];
        arr.a[j]=t;
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

    reverse(arr);
    display(arr);

    return 0;
}