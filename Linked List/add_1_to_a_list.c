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

struct node* reverseAList(struct node* head)
{
    struct node *curr = head, *prev = NULL, *Next = NULL;
    while (curr!=NULL)
    {
        Next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=Next;
    }
    head =  prev;
    return head;
}

struct node* add1ToAList(struct node* head)
{
    head = reverseAList(head);
    struct node* curr=head;
    int flag = 1;
    while(curr!=NULL && flag == 1)
    {
        if(curr->next == NULL && curr->data == 9)
        {
            curr->data = 1;
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->data = 0;
            temp->next=head;
            head=temp;
            curr=curr->next;
        }
        else if(curr->data==9)
        {
            curr->data=0;
            curr=curr->next;
        }
        else
        {
            curr->data = curr->data+1;
            curr = curr->next;
            flag=0;
        }
    }
    head = reverseAList(head);
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

    head = add1ToAList(head);
    display(head);

    return 0;
}