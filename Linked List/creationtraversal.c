#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void traversal(struct node* temp)
{
    while(temp!=NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//  user input 

int main()
{
    struct node *prev,*head,*p;
    int n,i;
    printf ("Number of elements: ");
    scanf("%d",&n);
    head=NULL;
    printf ("Number of elements: ");
    for(i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            prev->next=p;
        prev=p;
    }
    printf ("Your Linked List: ");
    traversal(head);
    return 0;
}

// without user input
/*
int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));

    head->data=2;
    head->next=second;
    second->data=3;
    second->next=third;
    third->data=4;
    third->next=NULL;
    traversal(head);
    return 0;
}
*/

// user input using adt

/*
struct node *create(struct node *head)
{

    struct node *p = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    p->next = NULL;
    struct node *ptr;
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

int main()
{

    int n;
    scanf("%d", &n);
    struct node *head;
    head = NULL;

    for (int i = 0; i < n; i++)
    {
        head = create(head);
    }
    display(head);

    return 0;
}
*/