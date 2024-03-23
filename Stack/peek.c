#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *array;
};

int isFull(struct Stack *stack)
{
    if (stack->top == stack->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    return 0;
}

void push(struct Stack *stack, int val)
{
    if (isFull(stack))
        printf("Stack overflow for %d \n", val);
    else
    {
        stack->top++;
        stack->array[stack->top] = val;
    }
}

int peek(struct Stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Not valid\n");
        return -1;
    }
    else
        return ptr->array[ptr->top - i + 1];
}

int stackTop(struct Stack *ptr)
{
    return ptr->array[ptr->top];
}

int stackBottom(struct Stack *ptr)
{
    return ptr->array[0];
}

int main()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = 4;
    stack->top = -1;
    stack->array = (int *)malloc(stack->size * sizeof(int));

    printf("before pushing empty: %d\n", isEmpty(stack));
    printf("before pushing full: %d\n", isFull(stack));

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    printf("After pushing empty: %d\n", isEmpty(stack));
    printf("After pushing full: %d\n", isFull(stack));

    for (int j = 1; j <= stack->top + 1; j++)
    {
        printf("Value at position %d is %d.\n", j, peek(stack, j));
    }

    printf("Topmost value is %d.\n", stackTop(stack));
    printf("Lowermost value is %d.\n", stackBottom(stack));

    return 0;
}