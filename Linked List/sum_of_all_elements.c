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

int sum(struct node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
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
    printf("%d\n", sum(head));
    return 0;
}