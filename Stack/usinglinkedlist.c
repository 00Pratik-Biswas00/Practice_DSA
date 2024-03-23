#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void linkedPrint(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node* top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int isFull(struct node* top)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    if(n==NULL)
        return 1;
    else
        return 0;
}

struct node* push(struct node* top, int val)
{
    if(isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->next =  top;
        top = n;
        return top;
    }
}

int pop(struct node* tp)
{
    if(isEmpty(tp))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node* n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct node* ptr=top;
    for(int i=0 ; (i<pos-1 && ptr!=NULL) ; i++)
    {       
        ptr = ptr->next;
    }
    if(ptr!=NULL)
        return ptr->data;
    else
        return 0;
}

int main()
{

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    linkedPrint(top);

//    printf("Popped Element: %d\n", pop(top));

    linkedPrint(top);
    for(int i=1;i<=3;i++)
        printf("Peeked element at index %d is: %d\n", i, peek(i));


    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void linkedPrint(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    return 0;
}

struct node *push(struct node *top, int val)
{
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = val;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node *n = ptr;
        top = ptr->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the data: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        top = push(top, data);
    }

    linkedPrint(top);

    printf("Popped Element: %d\n", pop(top));

    return 0;
}
*/


