#include<stdio.h>
#include<stdlib.h>

struct circular_queue
{
    int size;
    int f;      //deletion end
    int r;      // insertion end
    int *arr;
};

// check empty

int isEmpty(struct circular_queue *q)
{
    if(q->f==q->r)
        return 1;
    return 0;
}

// check full

int isFull(struct circular_queue *q)
{
    if((q->r+1)%q->size==q->f)
        return 1;
    return 0;
}

// insertion

void enqueue(struct circular_queue *q, int val)
{
    if(isFull(q))
        printf("Queue is overflow\n");
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued element is: %d\n",val);
    }
}

int dequeue(struct circular_queue *q)
{
    int val=-1;
    if(isEmpty(q))
        printf("Queue is underflow\n");
    else{
        q->f=(q->f+1)%q->size;
        val=q->arr[q->f];
        return val;
    }
}

int main()
{
    struct circular_queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));

    if(isEmpty(&q))
    printf("Queue is empty\n");
    if(isFull(&q))
    printf("Queue is full\n");

    enqueue(&q,5);
    enqueue(&q,45);

    if(isEmpty(&q))
    printf("Queue is empty\n");
    if(isFull(&q))
    printf("Queue is full\n");

    printf("Dequeued element is: %d\n",dequeue(&q));

    return 0;
}