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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int intersection_point(struct node *head1, struct node *head2)
{
    struct node *ptr1 = head1, *ptr2 = head2;
    int count1 = 0, count2 = 0, diff;
    while (ptr1)
    {
        count1++;
        ptr1 = ptr1->next;
    }
    while (ptr2)
    {
        count2++;
        ptr2 = ptr2->next;
    }
    ptr1 = head1;
    ptr2 = head2;
    diff = abs(count1 - count2);
    if (count1 > count2)
    {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    }
    else if (count2 > count1)
    {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1)
        return ptr1->data;
    return -1;
}

int main()
{

    // 10 15 30       ||      3 6 9 15 30

    struct node *head1, *head2, *newNode;
    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head1->data = 100;
    head2->data = 3;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 6;
    head2->next = newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 999;
    head2->next->next = newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 115;
    head2->next->next->next = newNode;
    head1->next = newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 30;
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    display(head1);
    display(head2);

    printf("\n\n\n\n");

    printf("%d\n", intersection_point(head1, head2));
    return 0;
}