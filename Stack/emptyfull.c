#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    int* array;
};

int isFull(struct Stack* stack)
{
    if( stack->top == stack->size-1)
        return 1;
    return 0;
}

int isEmpty(struct Stack* stack)
{
    if( stack->top == -1)
        return 1;
    return 0;
}



int main()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 1;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    stack->array[0]=1;
    stack->top++;

    if(isEmpty(stack))
        printf("Empty stack\n");
    else
        printf("Non-empty stack\n");
    if(isFull(stack))
        printf("Full stack\n");
    else
        printf("Not a full stack\n");
    return 0;
}