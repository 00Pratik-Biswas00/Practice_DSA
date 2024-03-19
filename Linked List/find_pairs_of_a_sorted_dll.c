#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL, *last = NULL;

void traversal(struct node *ptr)
{
    printf("NULL->");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void pairSum(struct node *head, int x)
{

    struct node *first = head;
    struct node *second = head;
    while (second->next != NULL)
        second = second->next;
 
    // To track if we find a pair or not
    int found = 0,c=0;
 
    // The loop terminates when two pointers
    // cross each other (second->next
    // == first), or they become same (first == second)
    while (first != second && second->next != first)
    {
        // pair found
        if ((first->data + second->data) == x)
        {
            found = 1;
        c++;
            printf("(%d,%d)\n",first->data,second->data);
 
            // move first in forward direction
            first = first->next;
 
            // move second in backward direction
            second = second->prev;
        }
        else
        {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
    // if pair is not present
    if (found == 0)
        printf("No pair found");
    else
        printf("no. of pairs: %d  \n",c);
}

void createList(int n)
{
    struct node *newNode;

    /*
     * Create and link head node
     */
    head = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &head->data);
    head->prev = NULL;
    head->next = NULL;
    last = head;

    /*
     * Create and link rest of the n-1 nodes
     */
    for (int i = 1; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newNode->data);
        newNode->prev = last; // Link new node with the previous node
        newNode->next = NULL;
        last->next = newNode; // Link previous node with the new node
        last = newNode;       // Make new node as last/previous node
    }
}

int main()
{
    int n;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);
    traversal(head);
    int x = 7;

    pairSum(head, x);

    return 0;
}