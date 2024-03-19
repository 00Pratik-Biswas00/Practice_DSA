#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *prev = NULL;

void display(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("Circle\n");
}

void create()
{
    // Create new node
    struct node *p = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    // Checks if the list is empty.
    if (head == NULL)
    {
        // If list is empty, both head and tail would point to new node.
        head = p;
        prev = p;
        p->next = head;
    }
    else
    {
        // tail will point to new node.
        prev->next = p;
        // New node will become new tail.
        prev = p;
        // Since, it is circular linked list tail will point to head.
        prev->next = head;
    }
}

void splitList(struct node *head, struct node **head1, struct node **head2)
{
    struct node *low = head, *high = head->next;
    while (high != head && (high->next) != head)
    {
        low = low->next;
        high = high->next->next;
    }
    *head1 = head;
    *head2 = low->next;
    low->next = *head1;
    struct node *curr;
    curr = *head2;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = *head2;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        create();
    }
    display(head);

//    splitList(head, &head1, &head2);
//    display(head1);
//    display(head2);
    return 0;
}
