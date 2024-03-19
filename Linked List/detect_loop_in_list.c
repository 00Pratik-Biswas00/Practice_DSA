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

int detectLoop(struct node *head)   // hare and tortoise algo 
{
    if (!head)
        return 0;

    struct node *low = head;
    struct node *high = head;

    while (high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
            return 1;
    }

    return 0;
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
        {
            head = p;
        }
        else
        {
            prev->next = p;
        }
        prev = p;
    }

    head->next = head; // creating the loop manually (if u want to stop the loop omit the line)

    if (detectLoop(head))
        printf("Loop is detected\n");
    else
        printf("Loop is not detected\n");

    return 0;
}