#include<stdio.h>

void display(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int insertArray(int arr[], int size, int element, int capacity, int index)
{
    if(size>=capacity)
        return -1;
    for(int i = size-1; i >= index; i--)
        arr[i+1]=arr[i];
    arr[index]=element;
    return 1;
}

int main()
{
    int c; 
    printf("enter the capacity: ");
    scanf("%d",&c);
    int arr[c];

    int size;
    printf("enter the size: ");
    scanf("%d",&size);

    printf("enter the array: ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);

    int element, index;
    printf("enter the element, index: ");
    scanf("%d%d",&element,&index);

    printf("Before insertion: ");
    display(arr,size);
    
    printf("After insertion: ");
    if(insertArray(arr,size,element,c,index)==1)
    {
        size  += 1;
        display(arr,size);
    }
    else
        printf("Insertion failed\n");
    

    return 0;
}