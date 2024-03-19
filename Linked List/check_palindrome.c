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

struct node *create(struct node*  head)
{
    struct node *prev, *p=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&p->data);
    p->next=NULL;
    if(head==NULL){
        head=p;
        prev=head;
        return head;
    }
    else{
        prev->next=p;
        prev=p;
        return head;
    }
}

int palindrome(struct node *head)
{
    struct node *slow=head,*fast=head;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct node *prev=NULL, *next, *curr= slow;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    fast = head;
    while(prev!=NULL)
    {
        if(fast->data!=prev->data)
            return 0;
        prev=prev->next;
        fast=fast->next;
    }
    return 1;
}

int main()
{
    struct node* head =NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head = create(head);
    }
    display(head);

    if(palindrome(head))
        printf("the linked list is palindrome\n");
    else
        printf("the linked list is not a palindrome\n");
    return 0;
}