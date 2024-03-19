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

struct node* insertAtHead(struct node* head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p = head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

struct node* insertAtEnd(struct node* head, int data)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node* p = head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    
    p->next=ptr;
    ptr->next=head;
    return head;
}

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
    third->next=head;

    printf("Normal: ");
    Traversal(head);

    printf("\nHead: ");
    head = insertAtHead(head,1);
    Traversal(head);

    printf("\nEnd: ");
    head = insertAtEnd(head,7);
    Traversal(head);

    printf("\nIndex: ");
    head = insertAtMid(head,33,2);
    Traversal(head);



    return 0;
}


/*


struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *ptr = NULL;

void create()
{
    struct node *p = (struct node*)malloc(sizeof(struct node)), *ptr;
    scanf("%d",&p->data);
    if(head==NULL)
    {
        head= p;
        ptr=head;
        p->next=head;
    }
    else
    {
        ptr->next=p;
        ptr=p;
        ptr->next = head;
    }
}

void traversal(struct node* p)
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++)
    create();
    traversal(head);
}



*/





