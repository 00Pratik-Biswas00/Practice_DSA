#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild, *rchild;
    int data;
} *root = NULL;

void insert_element(int key)
{
    struct node *t = root, *r, *p;
    if (root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

//iterative

struct node *search_node(int key)
{
    struct node *t = root;

    while (t != NULL)
    {
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return t;
    }
    return NULL;
}

//recursive

struct node *recursive_search_node(struct node *t, int key)
{
    if (t == NULL)
        return NULL;

        
    if (key < t->data)
        return recursive_search_node(t->lchild, key);
    else if (key > t->data)
        return recursive_search_node(t->rchild, key);
    else
        return t;
}

int main()
{
    insert_element(24);
    insert_element(28);
    insert_element(16);
    insert_element(07);
    insert_element(21);
    insert_element(13);
    insert_element(14);
    insert_element(27);

    Inorder(root);

    struct node *k, *c;
    k = search_node(2);
    if (k != NULL)
        printf("\nelement %d is present\n", k->data);
    else
        printf("\nelement is not present\n");

    c = recursive_search_node(root, 16);
    if (c != NULL)
        printf("\nelement %d is present\n", c->data);
    else
        printf("\nelement is not present\n");
    return 0;
}