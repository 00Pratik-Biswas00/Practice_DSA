#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL, *last = NULL;


int countPairs(struct node *first, struct node *second, int value)
{
    int count = 0;

    while (first != NULL && second != NULL && first != second && second->next != first)
    {

        // pair found
        if ((first->data + second->data) == value)
        {

            // increment count
            count++;

            // move first in forward direction
            first = first->next;

            // move second in backward direction
            second = second->prev;
        }

        // if sum is greater than 'value'
        // move second in backward direction
        else if ((first->data + second->data) > value)
            second = second->prev;

        // else move first in forward direction
        else
            first = first->next;
    }

    // required count of pairs
    return count;
}


int countTriplets(struct node *head, int x)
{
    // if list is empty
    if (head == NULL)
        return 0;

    struct node *current, *first, *last;
    int count = 0;

    // get pointer to the last node of
    // the doubly linked list
    last = head;
    while (last->next != NULL)
        last = last->next;

    // traversing the doubly linked list
    for (current = head; current != NULL; current = current->next)
    {

        // for each current node
        first = current->next;

        // count pairs with sum(x - current->data) in the range
        // first to last and add it to the 'count' of triplets
        count += countPairs(first, last, x - current->data);
    }

    // required count of triplets
    return count;
}

void createList(int n)
{
    struct node *newNode;

    if (n >= 1)
    {
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
}

int main()
{
    int n;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);

    int x = 15;

    printf("%d\n", countTriplets(head, x));

    return 0;
}