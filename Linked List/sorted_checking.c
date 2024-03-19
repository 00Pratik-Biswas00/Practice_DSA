#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

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

int IsSorted(struct node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
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
    display(head);

    if (IsSorted(head) == 0)
        printf("Not sorted\n");
    else
        printf("Sorted\n");

    return 0;
}