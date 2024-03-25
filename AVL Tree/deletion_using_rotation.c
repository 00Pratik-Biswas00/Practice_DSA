#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild, *rchild;
    int data, height;
} *root = NULL;

int height_node(struct node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int balance_factor(struct node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct node *LL_rotation(struct node *p)
{
    struct node *pl = p->lchild, *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = height_node(p);
    pl->height = height_node(pl);


    return pl;
}

struct node *LR_rotation(struct node *p)
{
    struct node *pl = p->lchild, *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = p;
    plr->lchild = pl;

    plr->height = height_node(plr);
    pl->height = height_node(pl);
    p->height = height_node(p);


    return plr;
}

struct node *RR_rotation(struct node *p)
{
    struct node *pr = p->rchild, *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = height_node(p);
    pr->height = height_node(pr);


    return pr;
}

struct node *RL_rotation(struct node *p)
{
    struct node *pr = p->rchild, *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    prl->height = height_node(prl);
    pr->height = height_node(pr);
    p->height = height_node(p);


    return prl;
}

struct node *recursive_Insert(struct node *t, int key)
{
    struct node *p = NULL;
    if (t == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->height = 1;
        p->rchild = p->lchild = NULL;
        return p;
    }

    if (key < t->data)
        t->lchild = recursive_Insert(t->lchild, key);
    else if (key > t->data)
        t->rchild = recursive_Insert(t->rchild, key);

    t->height = height_node(t);

    if (balance_factor(t) > 1 && balance_factor(t->lchild) == 1)
        return LL_rotation(t);
    else if (balance_factor(t) >1 && balance_factor(t->lchild) == -1)
        return LR_rotation(t);
    else if (balance_factor(t) <-1 && balance_factor(t->rchild) == -1)
        return RR_rotation(t);
    else if (balance_factor(t) <-1 && balance_factor(t->rchild) == 1)
        return RL_rotation(t);

    return t;
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
        if (height_node(p->lchild) > height_node(p->rchild))
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

    if(p==NULL) return p;

    p->height=height_node(p);


    if (balance_factor(p) >1 && balance_factor(p->lchild) >=0)
        return LL_rotation(p);
    else if (balance_factor(p) >1 && balance_factor(p->lchild) <0)
        return LR_rotation(p);
    else if (balance_factor(p) <-1 && balance_factor(p->rchild) <=0)
        return RR_rotation(p);
    else if (balance_factor(p) <-1 && balance_factor(p->rchild) >0)
        return RL_rotation(p);

    return p;
}


void Pre_order(struct node *p)
{
    if (p)
    {

        printf("%d ", p->data);
        Pre_order(p->lchild);
        Pre_order(p->rchild);
    }
}

int main()
{
    
    root = recursive_Insert(root, 9);
    recursive_Insert(root, 5);
    recursive_Insert(root, 10);
    recursive_Insert(root, 0);
    recursive_Insert(root, 6);
    recursive_Insert(root, 11);
    recursive_Insert(root, -1);
    recursive_Insert(root, 1);
    recursive_Insert(root, 2);

    Pre_order(root);
    printf("\n");
    root = delete_node(root,10);
    Pre_order(root);
    return 0;
}
