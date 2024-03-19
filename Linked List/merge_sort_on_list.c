#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
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

void findMiddle(struct node *curr, struct node **first, struct node **second)
{
    struct node *low, *high;
    low = curr;
    high = curr->next;
    while (high != NULL)
    {
        high = high->next;
        if (high != NULL)
        {
            low = low->next;
            high = high->next;
        }
    }
    *first = curr;
    *second = low->next;
    low->next = NULL;
}

struct node *mergeBoth(struct node *first, struct node *second)
{
    struct node *ans = NULL;
    if (!first)
        return second;
    if (!second)
        return first;
    if (first->data <= second->data)
    {
        ans = first;
        ans->next = mergeBoth(first->next, second);
    }
    else
    {
        ans = second;
        ans->next = mergeBoth(first, second->next);
    }
    return ans;
}

void mergeSorting(struct node **head)
{
    struct node *curr = *head, *first, *second;
    if (!curr || !curr->next)
        return;

    findMiddle(curr, &first, &second);

    mergeSorting(&first);
    mergeSorting(&second);
    *head = mergeBoth(first, second);
}

int main()
{
    struct node *head = NULL;
    struct node *h = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = create(head);
    }
    display(head);

    printf("Sorted Linked List is: \n");
    
    mergeSorting(&head);
    display(head);
    return 0;
}