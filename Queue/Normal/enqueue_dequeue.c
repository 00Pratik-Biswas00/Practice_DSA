#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;      //deletion end
    int r;      // insertion end
    int *arr;
};

// check empty

int isEmpty(struct queue *q)
{
    if(q->f==q->r)
        return 1;
    return 0;
}

// check full

int isFull(struct queue *q)
{
    if(q->r==q->size-1)
        return 1;
    return 0;
}

// insertion

void enqueue(struct queue *q, int val)
{
    if(isFull(q))
        printf("Queue overflow\n");
    q->r++;
    q->arr[q->r] = val;
    printf("Enqueued element is: %d\n",val);
}

// deletion

int dequeue(struct queue *q)
{
    int val=-1;
    if(isEmpty(q))
        printf("Queue underflow\n");
    q->f++;
    val = q->arr[q->f];
    return val;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));

    if(isEmpty(&q))
    printf("Queue is empty\n");
    if(isFull(&q))
    printf("Queue is full\n");

    enqueue(&q,10);
    enqueue(&q,20);

    printf("Dequeued element: %d\n",dequeue(&q));

    return 0;
}