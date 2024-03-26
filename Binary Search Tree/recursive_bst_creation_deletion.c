#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild, *rchild;
    int data;
} *root = NULL;

struct node *recursive_insert(struct node *t, int key)
{
    struct node *p = NULL;

    if (t == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p;
    }

    if (key < t->data)
        t->lchild = recursive_insert(t->lchild, key);
    else if (key > t->data)
        t->rchild = recursive_insert(t->rchild, key);

    return t;
}

int height_bst(struct node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height_bst(p->lchild);
    y = height_bst(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct node *Inorder_predecessor(struct node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct node *Inorder_successor(struct node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct node *delete_node(struct node *p, int key)
{
    struct node *q;
    if (p == NULL)
        return NULL;

    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
        p->lchild = delete_node(p->lchild, key);
    else if (key > p->data)
        p->rchild = delete_node(p->rchild, key); // searching
    else
    {
        if (height_bst(p->lchild) > height_bst(p->rchild))
        {
            q = Inorder_predecessor(p->lchild);
            p->data = q->data;
            p->lchild = delete_node(p->lchild, q->data);
        }
        else
        {
            q = Inorder_successor(p->rchild);
            p->data = q->data;
            p->rchild = delete_node(p->rchild, q->data);
        }
    }
    return p;
}

void Inorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Inorder(p->lchild);
        
        Inorder(p->rchild);
    }
}

int main()
{
    root = recursive_insert(root, 9);
    recursive_insert(root, 5);
    recursive_insert(root, 10);
    recursive_insert(root, 0);
    recursive_insert(root, 6);
    recursive_insert(root, 11);
    recursive_insert(root, -1);
    recursive_insert(root, 1);
    recursive_insert(root, 2);
    Inorder(root);
    printf("\n\n");
    delete_node(root, 21);
    Inorder(root);

    return 0;
}