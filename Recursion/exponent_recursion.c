#include <stdio.h>

// normal approach

int fun(int m,int n)
{
    if(n==0)
        return 1;
    else
        return fun(m,n-1)*m;
}

// better approach
int po(int m,int n)
{
    if(n==0) return 1;
    if(n%2==0) return po(m*m,n/2);
    else return po(m*m,(n-1)/2)*m;
}

int main()
{
    int m,n;
    scanf("%d %d",&m , &n);
//    printf("%d\n",fun(m,n));
    printf("%d\n",po(m,n));
    return 0;
}