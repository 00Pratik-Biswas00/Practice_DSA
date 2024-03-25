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

        if (root = p)
            root = pl;
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

        if (root = p)
            root = plr;
        return plr;
}

struct node *RR_rotation(struct node *p)
{
    struct node *pr = p->rchild, *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = height_node(p);
    pr->height = height_node(pr);
    
    if (root = p)
    {
        root = pr;
    }
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


        if (root = p)
            root = prl;
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

    if (balance_factor(t) == 2 && balance_factor(t->lchild) == 1)
        return LL_rotation(t);
    else if (balance_factor(t) == 2 && balance_factor(t->lchild) == -1)
        return LR_rotation(t);
    else if (balance_factor(t) == -2 && balance_factor(t->rchild) == -1)
        return RR_rotation(t);
    else if (balance_factor(t) == -2 && balance_factor(t->rchild) == 1)
        return RL_rotation(t);

    return t;
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
    // for LLRotation
    /*
        root = recursive_Insert(root, 30);
        recursive_Insert(root, 20);
        recursive_Insert(root, 10);
        recursive_Insert(root, 5);
        recursive_Insert(root, 15);
        recursive_Insert(root, 25);
        recursive_Insert(root, 28);
        recursive_Insert(root, 40);
        recursive_Insert(root, 50);
        recursive_Insert(root, 4);
    */

    // for LRRotation
    /*
        root = recursive_Insert(root, 44);
        recursive_Insert(root, 30);
        recursive_Insert(root, 76);
        recursive_Insert(root, 16);
        recursive_Insert(root, 39);
        recursive_Insert(root, 37);
    */

    // for RRRotation
     root = recursive_Insert(root, 18);
     root =  recursive_Insert(root, 12);
     root =  recursive_Insert(root, 6);
     root =  recursive_Insert(root, 9);
     root =  recursive_Insert(root, 21);
    //  recursive_Insert(root, 90);

    // for RLRotation

    // root = recursive_Insert(root, 18);
    // root = recursive_Insert(root, 12);
    // root = recursive_Insert(root, 6);
    // root = recursive_Insert(root, 9);
    // root = recursive_Insert(root, 21);
    // recursive_Insert(root, -1);
    // recursive_Insert(root, 1);
    // recursive_Insert(root, 2);

    Pre_order(root);

    return 0;
}
