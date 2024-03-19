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

void startingPointOfALoop(struct node *head) // hare and tortoise algo
{
    if (!head)
        return;

    struct node *low = head, *high = head;

    while (low != NULL && high != NULL && high->next != NULL)
    {
        low = low->next;
        high = high->next->next;
        if (low == high)
        {
            break;
        }
    }
//   if (low == head)
//   {
//       printf("%d  ", head->data);
//   }
//   else if (low == high)
//   {
//       low = head;
//       while (low->next != high->next)
//       {
//           low = low->next;
//           high = high->next;
//       }
//       printf("%d  ", low->next->data);
//   }

    low = head;
        while (low->next != high->next)
        {
            low = low->next;
            high = high->next;
        }
        printf("%d  ", low->next->data);
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

    head->next->next->next = head->next->next; // creating the loop manually for 3 elements (if u want to stop the loop omit the line

    startingPointOfALoop(head);
    //    display(head);

    return 0;
}