#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[100];
    int size;
    int length;
};
void Display(struct Array *arr, int n)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr->A[i]);
}
struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 100;
    return arr3;
}
int main()
{
     //struct Array arr1 = {{2, 9, 21, 28, 35, 40}, 12, 6};

    struct Array arr1;
    arr1.size=100;
    arr1.length=3;

    // arr1.A=(int *)malloc(arr1.size*sizeof(int));

    for (int i = 0; i < arr1.length; i++)
        scanf("%d", &arr1.A[i]);


   // struct Array arr2 = {{2, 3, 16, 18, 20}, 12, 5};

    struct Array arr2;
    arr2.size=100;
    arr2.length=3;

        // arr2.A=(int *)malloc(arr2.size*sizeof(int));


    for (int i = 0; i < arr2.length; i++)
        scanf("%d", &arr2.A[i]);



    struct Array *arr3;




    Display(&arr1, arr1.length);
    Display(&arr2,arr2.length);
    arr3 = Merge(&arr1, &arr2);
    Display(arr3,arr3->length);
    return 0;
}