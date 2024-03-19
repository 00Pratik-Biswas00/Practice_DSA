#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void Traversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

int searchValue(struct node* head, int value)
{
    struct node* p = head;
    int i=0;
    while(p->next!=NULL)  
    {
        if(p->data==value)
        return i;
        else
        {
            i++;
            p=p->next;
        }
        
    }
    return -1;
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
    seventh->next=NULL;

    printf("Normal: ");
    Traversal(head);

    int val;
    printf("Enter the value you  want to found: ");
    scanf("%d",&val);

    if(searchValue(head,val))
        printf("The index of the value is: %d\n", searchValue(head,val));
    else
        printf("Not found\n");

    
    

    
    return 0;
}