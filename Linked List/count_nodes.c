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

// iterative

int count(struct node *p)
{
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}

// recursive

int Count(struct node *p)
{
    if (p == NULL)
        return 0;
    return Count(p->next) + 1;
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
    printf("%d\n", count(head));
    printf("%d", Count(head));
    return 0;
}