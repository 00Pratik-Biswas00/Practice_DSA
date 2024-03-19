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

int checkSorted(struct array arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr.a[i]>arr.a[i+1])
            return -1;
    }
    return 1;
}

void insertInASortedPosition(struct array *arr, int key)
{
        int i=arr->length-1;
        if(arr->length==arr->size) return;
        while(arr->a[i]>key)
        {
            arr->a[i+1]=arr->a[i];
            i--;
        }
        arr->a[i+1]=key;
        arr->length++;
}

void moveAllNegToFirst(struct array *arr)
{
    int i=0,j=arr->length-1;
    while(i<j)
    {
    while(arr->a[i]<0)  i++;
    while(arr->a[j]>0)  j--;
    if(i<j)
    {
        int temp = arr->a[i];
        arr->a[i]=arr->a[j];
        arr->a[j]=temp;
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
        display(arr);

//  ------------------------------------------------

//    if(checkSorted(arr,arr.length)==1)
//        printf("sorted\n");
//    else
//        printf("not sorted\n");
//    }


//    scanf("%d", &key);
//    insertInASortedPosition(&arr,key);
//    display(arr);
    
    moveAllNegToFirst(&arr);
    display(arr);
}
    return 0;
}