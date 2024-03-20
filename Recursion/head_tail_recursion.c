#include<stdio.h>

// head recursion 
void fun(int a)
{
    if(a>0)
    {
        fun(a-1);       // fun call before printing
        printf("%d  ",a);
    }
}


// tail recursion
void fun1(int a)
{
    if(a>0)
    {
        printf("%d  ",a);
        fun(a-1);       // fun call after printing
    }
}

int main()
{
    int x=3;
    fun(x);
    printf("\n");
    fun1(x);
    return 0;
}



