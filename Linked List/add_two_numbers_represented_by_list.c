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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *create(struct node *head)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = NULL;
    struct node *ptr;
    if (head == NULL)
    {
        head = p;
        ptr = head;
        return head;
    }
    else
    {
        ptr->next = p;
        ptr = p;
        return head;
    }
}

/* Function to create a
new node with given data */
struct node *newNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *reverseAList(struct node *head)
{
    struct node *curr = head, *prev = NULL, *Next = NULL;
    while (curr != NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    head = prev;
    return head;
}

struct node *addTwoNumbersOfAList(struct node *first, struct node *second)
{
    first = reverseAList(first);
    second = reverseAList(second);
    int s, c = 0;
    struct node *temp;
    struct node *res = NULL;
    struct node *curr = NULL;
    while (first != NULL || second != NULL)
    {
        s = c + (first ? first->data : 0) + (second ? second->data : 0);
        c = (s >= 10) ? 1 : 0;
        s = s % 10;
        temp = newNode(s);
        if (res == NULL)
            res = temp;
        else
            curr->next = temp;
        curr = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (c > 0)
    {
        temp->next = newNode(c);
    }
    res = reverseAList(res);
    return res;
}

int main()
{
    struct node *head = NULL, *head2 = NULL, *res = NULL;

    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = create(head);
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        head2 = create(head2);
    }

    display(head);
    display(head2);
    res = addTwoNumbersOfAList(head, head2);
    display(res);
    return 0;
}