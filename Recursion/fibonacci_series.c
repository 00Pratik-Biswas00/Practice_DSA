#include <stdio.h>

int iteration(int n)
{
    int t0 = 0, t1 = 1, s = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int recursion(int n)
{
    if (n <= 1)
        return n;
    else
        return recursion(n - 1) + recursion(n - 2);
}

//best approach 

int f[10];
int betterRecursion(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = betterRecursion(n - 2);
        if (f[n - 1] == -1)
            f[n - 1] = betterRecursion(n - 1);
        return f[n - 1] + f[n - 2];
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        // printf("%d ", recursion(i));
        //printf("%d ", iteration(i));

        f[i] = -1;
        printf("%d ", betterRecursion(i));
    }
    return 0;
}