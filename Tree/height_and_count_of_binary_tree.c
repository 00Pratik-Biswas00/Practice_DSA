#include <stdio.h>
#include <stdlib.h>
#include "Queue_for_binary_tree.h"

struct Node *root = NULL;

void create_binaryTree()
{
    struct Node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);

    printf("Enter the root of the tree: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter the left child of %d: ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter the right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

int count_nodes(struct Node *root)
{
    if (root)
        return count_nodes(root->lchild) + count_nodes(root->rchild) + 1;
    return 0;
}

int height_tree(struct Node *root)
{
    int x, y;
    if (root)
    {
        x = height_tree(root->lchild);
        y = height_tree(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

int sum_tree(struct Node *root)
{
    if (root)
        return sum_tree(root->lchild) + sum_tree(root->rchild) + root->data;
    return 0;
}

int nodes_deg0(struct Node *root)
{
    int x, y;
    if (root)
    {
        x = nodes_deg0(root->lchild);
        y = nodes_deg0(root->rchild);
        if (!root->lchild && !root->rchild)
            return x + y + 1;
        else
            return x + y;
    }
}

int nodes_deg2(struct Node *root)
{
    int x, y;
    if (root)
    {
        x = nodes_deg2(root->lchild);
        y = nodes_deg2(root->rchild);
        if (root->lchild && root->rchild)
            return x + y + 1;
        else
            return x + y;
    }
}

int nodes_deg1_deg2(struct Node *root)
{
    int x, y;
    if (root)
    {
        x = nodes_deg1_deg2(root->lchild);
        y = nodes_deg1_deg2(root->rchild);
        if (root->lchild || root->rchild)
            return x + y + 1;
        else
            return x + y;
    }
}

int nodes_deg1(struct Node *root)
{
    int x, y;
    if (root)
    {
        x = nodes_deg1(root->lchild);
        y = nodes_deg1(root->rchild);
        if (root->lchild != NULL ^ root->rchild != NULL)
            return x + y + 1;
        else
            return x + y;
    }
}

int main()
{
    create_binaryTree();
    printf("Total nodes of the tree: %d \n", count_nodes(root));
    printf("Height of the tree: %d \n", height_tree(root) - 1);
    printf("Nodes with deg 0 of the tree: %d \n", nodes_deg0(root));
    printf("Nodes with exact deg 1 of the tree: %d \n", nodes_deg1(root));
    printf("Nodes with deg 2 of the tree: %d \n", nodes_deg2(root));
    printf("Nodes with deg 1 or deg 2 of the tree: %d \n", nodes_deg1_deg2(root));

    return 0;
}