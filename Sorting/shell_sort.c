#include <stdio.h>
#include<stdlib.h>

void ShellSort(int A[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}
int main()
{
    int a[] = {20, 14, 23, 6, 1, 5, 24, 8, 25, 2}, n = 10;

    ShellSort(a, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }


    return 0;
}