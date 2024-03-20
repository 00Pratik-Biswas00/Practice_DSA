#include <stdio.h>

int fun(int n)
{
    if(n==0)
        return 0;
    else
        return fun(n-1)+n;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",fun(n));
    return 0;
}