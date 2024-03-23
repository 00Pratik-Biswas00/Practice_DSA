#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int top;
    int size;
    char* array;
};

int isFull(struct stack* stack)
{
    if( stack->top == stack->size-1)
        return 1;
    return 0;
}

int isEmpty(struct stack* stack)
{
    if( stack->top == -1)
        return 1;
    return 0;
}

int stackTop(struct stack* ptr)
{
    return ptr->array[ptr->top];
}

void push(struct stack* stack, int val)
{
    if(isFull(stack))
        printf("Stack overflow for %d \n", val);
    else{
        stack->top++;
        stack->array[stack->top]=val;
    }
}

int pop(struct stack* ptr){
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

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->array = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    
    char* infix = "p-q-r/a";
    printf("ans in postfix is: %s\n",infixToPostfix(infix));
    return 0;
}