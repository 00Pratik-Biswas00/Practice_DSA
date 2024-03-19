#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

// printing

void traversal(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// head

struct node* insertAtHead(struct node* head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=head;
    head=ptr;
    return head;
}

// mid

struct node* insertAtMid(struct node* head, int data,  int index)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

// end

struct node* insertAtEnd(struct node* head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

// after node

struct node* insertAtAfterNode(struct node* head, struct node* prevnode, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}

int main()
{
    struct node* head;
    struct node* second;
    struct node* third;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data=2;
    head->next=second;
    second->data=4;
    second->next=third;
    third->data=6;
    third->next=NULL;
// before
    traversal(head);
// head
    head = insertAtHead(head,1);
    traversal(head);
// mid
    head = insertAtMid(head,3,2);
    traversal(head);
// end
    head = insertAtEnd(head,7);
    traversal(head);
// after node
    head = insertAtAfterNode(head,second,5);
    traversal(head);
    
    return 0;
}