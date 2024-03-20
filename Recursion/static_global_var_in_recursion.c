#include <stdio.h>

// static variables

int fun(int x)
{
    static int k = 0;
    if (x > 0)
    {
        k++;
        return fun(x - 1) + k;
    }
}

// global variables
int p = 0;
int fun2(int x)
{
    if (x > 0)
    {
        p++;
        return fun2(x - 1) + p;
    }
}

int main()
{
    int x = 3;
    printf("%d\n", fun(x));
    printf("%d\n", fun2(x));
    return 0;
}
