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

struct node* create(struct node *head)
{
    struct node *prev, *p = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL){
        head=p;
        prev = head;
        return head;
    }
    else{
        prev->next=p;
        prev=p;
        return head;
    }
}

struct node* findMiddle(struct node* head)
{
    struct node *low = head, *high = head;
    while (high!=NULL && high->next!=NULL)
    {
        low=low->next;
        high=high->next->next;
    }
    return low;
}

int main()
{
    struct node *head = NULL;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        head = create(head);
    }
    display(head);

    head = findMiddle(head);
    printf("middle element is: %d\n",head->data);
    return 0;
}