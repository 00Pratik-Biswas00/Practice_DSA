#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void traversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}

void sort(struct node* head, int n)
{
    struct node *temp1,  *temp2;
    int k;
    for(int i=0;i<n-1;i++)
	{
		temp1=head;
		temp2=temp1->next;
		for(int j=0;j<n-i-1;j++)
		{
			if(temp1->data > temp2->data)
			{
				k=temp1->data;
				temp1->data=temp2->data;
				temp2->data=k;
			}
			temp1=temp2;
			temp2=temp2->next;
		}
    }
}

int main()
{
    struct node *prev, *head, *p;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    head=NULL;
    printf("Enter the number of elements: ");
    for(int i=0;i<n;i++)
    {
        p = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next = NULL;
        if(head==NULL)
            head=p;
        else
            prev->next = p;
        prev = p;
    }
    sort(head,n);
    traversal(head);
    return 0;
}