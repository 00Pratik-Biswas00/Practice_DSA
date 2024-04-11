#include <stdio.h>
#include <stdlib.h>
#include "Stack_for_binary_tree.h"

struct Node *root = NULL;

void Tree_create()
{
    struct Node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);
    printf("Enter the root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void Iterative_Preorder(struct Node *p)
{
    struct stack st;
    stack_create(&st, 100);

    while (p || !isEmptyStack(&st))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&st, p);
            p = p->lchild;
        }

        else
        {
            p = pop(&st);
            p = p->rchild;
        }
    }
}

void Iterative_Inorder(struct Node *p)
{
    struct stack st;
    stack_create(&st, 100);

    while (p || !isEmptyStack(&st))
    {
        if (p)
        {
            push(&st, p);
            p = p->lchild;
        }

        else
        {
            p = pop(&st);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void Iterative_Postorder(struct Node *p)
{
    struct stack st;
    stack_create(&st, 100);

    do{
        while(p)
        {
            if(p->rchild)
                push(&st,p->rchild);
            push(&st,p);

            p=p->lchild;
        }

        p=pop(&st);

        if(p->rchild && peek(&st)==p->rchild)
        {
            pop(&st);
            push(&st,p);
            p=p->rchild;
        }
        else
        {
            printf("%d ", p->data);
                p = NULL;
        }
    }while(!isEmptyStack(&st));
    
}



int main()
{
    Tree_create();
    Iterative_Preorder(root);
    printf("\n");
    Iterative_Inorder(root);
    printf("\n");
    Iterative_Postorder(root);

    return 0;
}
