#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node *removeDuplicatesSorted(struct node *head)
{
    struct node *p = head, *dup;
    while (p->next != NULL)
    {
        if (p->data == p->next->data)
        {
            dup = p->next;
            p->next = p->next->next;
            free(dup);
        }
        else
            p = p->next;
    }
    return head;
}

int main()
{
    struct node *prev, *head, *p;
    int n;
    scanf("%d", &n);
    head = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            prev->next = p;
        prev = p;
    }

    head = removeDuplicatesSorted(head);
    display(head);

    return 0;
}