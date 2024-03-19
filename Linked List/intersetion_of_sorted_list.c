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
    struct node *ptr, *p = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = NULL;
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
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node *intersect(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1, *ptr2 = head2, *head = NULL, *curr = NULL, *temp;
    while (ptr1 && ptr2)
    {
        if (ptr1->data == ptr2->data)
        {
            if (head == NULL)
            {
                temp = newNode(ptr1->data);
                head = temp;
                curr = temp;
            }
            else
            {
                temp = newNode(ptr1->data);
                curr->next = temp;
                curr = curr->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else
        {
            if (ptr1->data < ptr2->data)
                ptr1 = ptr1->next;
            else
                ptr2 = ptr2->next;
        }
    }
    return head;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *head = NULL;

    int n, k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head1 = create(head1);
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        head2 = create(head2);
    }

    display(head1);
    display(head2);

    printf("\n\n\n\n");

    head = intersect(head1, head2);
    display(head);
    return 0;
}