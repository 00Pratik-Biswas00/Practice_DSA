#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void Traversal(struct node* head)
{
    struct node* ptr = head;
    do
    {
        printf("%d->",  ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    printf("Circle\n");
}

struct node* deleteAtHead(struct node* head)
{
    struct node* ptr = head;
    while(ptr->next!=head)  
    {
        ptr=ptr->next;
    }
    struct node* q = head;
    ptr->next = head->next;
    head=head->next;
    free(q);
    return head;
}

struct node* deleteAtIndex(struct node* head, int  index)
{
    struct node* p = head;
    struct node* q = head->next;
    for(int i=0;i<index-1;i++)  
    {
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node* deleteAtEnd(struct node* head)
{
    struct node* p = head;
    struct node* q = head->next;
    while(q->next!=head)  
    {
        p=p->next;
        q=q->next;
    }
    p->next = head;
    free(q);
    return head;
}

struct node* deleteValue(struct node* head, int value)
{
    struct node* p = head;
    struct node* q = head->next;
    while(q->data!=value && q->next!=NULL)  
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;
    struct node* fifth;
    struct node* sixth;
    struct node* seventh;

    head = (struct node*)malloc(sizeof(struct node*));
    second = (struct node*)malloc(sizeof(struct node*));
    third = (struct node*)malloc(sizeof(struct node*));
    fourth = (struct node*)malloc(sizeof(struct node*));
    fifth = (struct node*)malloc(sizeof(struct node*));
    sixth = (struct node*)malloc(sizeof(struct node*));
    seventh = (struct node*)malloc(sizeof(struct node*));

    head->data=2;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=4;
    third->next=fourth;
    fourth->data=5;
    fourth->next=fifth;
    fifth->data=6;
    fifth->next=sixth;
    sixth->data=7;
    sixth->next=seventh;
    seventh->data=8;
    seventh->next=head;

    printf("Normal: ");
    Traversal(head);

    printf("deleteAtHead: ");
    head = deleteAtHead(head);
    Traversal(head);

    printf("deleteAtIndex: ");
    head = deleteAtIndex(head,0);
    Traversal(head);

    printf("deleteAtEnd: ");
    head = deleteAtEnd(head);
    Traversal(head);

    printf("deleteValue: ");
    head = deleteValue(head,6);
    Traversal(head);
    
    return 0;
}