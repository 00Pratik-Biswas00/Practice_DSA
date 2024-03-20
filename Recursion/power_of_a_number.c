#include <stdio.h>
#include <stdlib.h>

int normal_power(int m, int n)
{
    if (n == 0)
        return 1;
    return normal_power(m, n - 1) * m; // 2^5 = (2*2*2*2) * 2 = (m*m..(n-1) times) * m
}

int better_approach_power(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return better_approach_power(m * m, n / 2);             // even number n/2 times mul
    else
        return better_approach_power(m * m, (n - 1) / 2) * m;   // odd number to even number for (n-1)/2 
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", normal_power(m, n));
    printf("%d", better_approach_power(m, n));
    return 0;
}