#include <stdio.h>

double fun(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s=1+x*s/n;
    return fun(x,n-1);
}

double fun1(int x, int n)
{
    int  s=1;
    double nu=1,de=1;
    for(int i=0;i<n;i++)
    {

        nu*=x;
        de*=i;
        s+=nu/de;
    }
    return s;
}

int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    printf("%lf\n", fun(x,n));
    printf("%lf\n", fun(x,n));
    return 0;
}