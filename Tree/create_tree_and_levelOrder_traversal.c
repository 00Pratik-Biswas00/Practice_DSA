#include<stdio.h>
#include<stdlib.h>
#include "Queue_for_binary_tree.h"

struct Node*root=NULL;
void create_tree()
{
    struct Node *p, *t;
    int x;
    printf("Enter the root of the data: ");
    scanf("%d",&x);

    struct queue q;
    create(&q,100);

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter the left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        printf("Enter the right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);

    while (!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }

        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }
    
}

int main()
{
    create_tree();
    LevelOrder(root);
    return 0;
}