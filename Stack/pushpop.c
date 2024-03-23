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

void push(struct Stack* stack, int val)
{
    if(isFull(stack))
        printf("Stack overflow for %d \n", val);
    else{
        stack->top++;
        stack->array[stack->top]=val;
    }
}

int pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->array[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 4;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    
    printf("before pushing empty: %d\n", isEmpty(stack));
    printf("before pushing full: %d\n", isFull(stack));

    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    push(stack,6);



    printf("After pushing empty: %d\n", isEmpty(stack));
    printf("After pushing full: %d\n", isFull(stack));
        
    printf("Popped %d from the stack\n", pop(stack));


    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size, top, *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}

void display(struct stack *s)
{
    int a = isEmpty(s), b = isFull(s);
    (a == 1) ? printf("stack is empty\n") : printf("stack is not empty\n");
    (b == 1) ? printf("stack is full\n") : printf("stack is not full\n");
}

void push(struct stack *s, int val)
{
    if (isFull(s))
        printf("Stack is overflow\n");
    s->top++;
    s->arr[s->top] = val;
}

int pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is underflow\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));

    int n, data;
    display(s);
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        push(s, data);
    }
    display(s);
    printf("Popped element is: %d\n", pop(s));
    return 0;
}
*/