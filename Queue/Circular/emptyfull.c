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

int main()
{
    struct circular_queue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));

    if(isEmpty(&q))
    printf("Queue is empty\n");
    if(isFull(&q))
    printf("Queue is full\n");
    return 0;
}