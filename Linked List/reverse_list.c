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

// iteration

struct node *reverseTheList(struct node *head)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *Next = NULL;
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

// recursion

struct node *reverse(struct node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct node *rest = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

// recursion in group of given size

struct node *reverse_KNode_List(struct node *head, int k)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *Next = NULL;
    int c=0;
    while (curr != NULL && c<k)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        c++;
    }
    if(Next!=NULL)
        head->next = reverse_KNode_List(Next,k);
    return prev;
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

    display(head);

    head = reverseTheList(head); // iteration
    display(head);

    head = reverse(head); // recursion
    display(head);

    int k;
    printf("enter the size of the group: ");

    scanf("%d",&k);
    head = reverse_KNode_List(head,k); // recursion in group of given size
    display(head);

    return 0;
}