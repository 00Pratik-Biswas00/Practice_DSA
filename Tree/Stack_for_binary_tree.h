#include <stdio.h>
#include <stdlib.h>
#include "Queue_for_binary_tree.h"

struct stack
{
    int top, size;
    struct Node **arr;
};

void stack_create(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->arr = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow.");
    else
    {
        st->top++;
        st->arr[st->top] = x;
    }
}

struct Node *pop(struct stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
        printf("Stack Underflow");
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

struct Node* peek(struct stack* st)
{
    if (st->top == -1)
        return NULL;
    return st->arr[st->top];
}

int isEmptyStack(struct stack *st)
{
    if (st->top == -1)
        return 1;
    else
        return 0;
}

int isFullStack(struct stack *st)
{
    if (st->top == st->size - 1)
        return 1;
    else
        return 0;
}