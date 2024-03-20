#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

int nCr(int n, int r)
{
    int num = fact(n),den=fact(r)*fact(n-r);
    return num / den;
}

// better approach

int NcR(int n,  int r)
{
    if(r==0 || r==n)    return 1;
    return NcR(n-1,r-1)+NcR(n-1,r);
}

int main()
{
    int n, r;
    scanf("%d%d", &n, &r);

    //printf("%d ", nCr(n, r));
    printf("%d ", NcR(n, r));

    return 0;
}