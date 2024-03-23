#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
        return 1;
    return 0;

}

void push(struct stack* ptr, char val)
{
    if(isFull(ptr))
        printf("stack overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(struct stack* ptr)
{
    if(isEmpty(ptr))
        printf("Stack underflow\n");
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isMatch(char a, char b)
{
    if(a=='('&& b==')')
        return 1;
    else if(a=='{'&& b=='}')
        return 1;
    else if(a=='['&& b==']')
        return 1;
    else
        return 0;
}

int parenthesis(char *ptr)
{
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));
    char popped;
    for(int i=0; ptr[i]!='\0';i++)
    {
        if(ptr[i]=='('|| ptr[i]=='{' || ptr[i]=='[')
        {
            push(sp,ptr[i]);
        }
        else if(ptr[i]==')'|| ptr[i]=='}' || ptr[i]==']')
        {
            if(isEmpty(sp))
                return 0;
            popped = pop(sp);
            if(!isMatch(popped,ptr[i]))
                return 0;
        }
    }

    if(isEmpty(sp))
        return 1;
    else
        return 0;

}


int main()
{
    char* sp = "[{(8)*(9)]+9}";

    if(parenthesis(sp))
        printf("Parenthesis matched\n");
    else
        printf("Parenthesis not matched\n");

    return 0;
}