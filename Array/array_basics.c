#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

struct array
{
    int *a, size, length;
};

void display(struct array *arr)
{
    for (int i = 0; i < arr->length; i++)
        printf("%d ", arr->a[i]);
    printf("\n");
}

void add(struct array *arr, int data)
{
    if (arr->length < arr->size)
        arr->a[arr->length++] = data;
}

void insert(struct array *arr, int index, int data)
{
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->a[i] = arr->a[i - 1];
        }
        arr->a[index] = data;
        arr->length++;
    }
}

void delete(struct array *arr, int index)
{
    printf("Deleted value: %d\n", arr->a[index]);
    if (index >= 0 && index <= arr->length)
    {
        for (int i = index; i <= arr->length; i++)
        {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
    }
}

void linear_search(struct array *arr, int key)
{
    int flag = 0;
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->a[i] == key)
        {
            printf("%d is present at index %d.\n", key, i);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("Key is not present.\n");
}

int binary_search(struct array *arr, int key)
{
    int l=0,h=arr->length-1,mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(arr->a[mid]==key)
        {
            return mid;
        }
        else if(arr->a[mid]<key) l=mid+1;
        else h=mid-1;
    }
    return -1;
}

void sum(struct array *arr)
{
    int s=0;
    for(int i=0;i<arr->length;i++)
    s+=arr->a[i];

    printf("Sum of all elements is: %d\n",s);
}

int r_sum(struct array arr, int n)
{
    if(n<0) return 0;
    return r_sum(arr,n-1)+arr.a[n];
}

void avg(struct array arr)
{
    printf("Average of all elements is: %d\n",r_sum(arr,arr.length-1)/arr.length);;
}

void max(struct array arr)
{
    int MAX = INT_MIN;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.a[i]>MAX) MAX = arr.a[i];
    }
    printf("Max element: %d\n",MAX);
}

void min(struct array arr)
{
    int MIN = INT_MAX;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.a[i]<MIN) MIN = arr.a[i];
    }
    printf("Min element: %d\n",MIN);
}

int main()
{
    struct array arr;
    int n, i;
    arr.length = 0;
    printf("Enter Size: ");
    scanf("%d", &arr.size);
    arr.a = (int *)malloc(arr.size * sizeof(int));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr.length = n;

    printf("Enter the elements: "); //1,2,3,4,5

    for (i = 0; i < n; i++)
        scanf("%d", &arr.a[i]);

    add(&arr, 6);
    display(&arr);

    insert(&arr, 2, 7);
    display(&arr);

    delete (&arr, 2);
    display(&arr);

    linear_search(&arr, 3);
    printf("4 is present at: %d\n",binary_search(&arr, 4));

    sum(&arr);
    printf("Sum in recursive way: %d\n", r_sum(arr, arr.length-1));

    avg(arr);

    max(arr);
    min(arr);
    return 0;
}