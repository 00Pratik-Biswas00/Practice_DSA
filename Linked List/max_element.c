#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *prev, *p = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        prev = head;
        return head;
    }
    else
    {
        prev->next = p;
        prev = p;
        return head;
    }
}

int max(struct node *p)
{
    int m = -32768; // MIN_INT
    while (p != NULL)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int Max(struct node *p)
{
    int x = 0;
    if (p == 0)
        return 0;
    x = Max(p->next);
    return x > p->data ? x : p->data;
}

int main()
{
    struct node *head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = create(head);
    }
    printf("%d\n", max(head));
    printf("%d\n", Max(head));
    return 0;
}