#include <stdio.h>

double fun(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
        r = fun(x, n - 1);
        p = p * x;
        f = f * n;
    return r + p / f;
}

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%lf\n", fun(x,n));
    return 0;
}