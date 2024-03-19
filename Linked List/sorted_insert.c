#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void display()
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void SortedInsert(struct node **H, int x)
{
    struct node *t, *q = NULL, *p = *H;

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int main()
{
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        SortedInsert(&head, data);
    }
    display();

    //    SortedInsert(&head, 5);
    //    SortedInsert(&head, 15);
    //    SortedInsert(&head, 2);
    //    SortedInsert(&head, 1);
    //    display();

    return 0;
}