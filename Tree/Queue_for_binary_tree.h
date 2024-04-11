#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild;
};

struct queue
{
    int front, rear, size;
    struct Node **arr;
};

void create(struct queue *q, int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->arr=(struct Node **)malloc(q->size*sizeof(struct Node*));
}

int isEmpty(struct queue q)
{
    return q.front==q.rear;
}

int isFull(struct queue q)
{
    return (q.rear+1)%q.size == q.front;
}

void enqueue(struct queue *q, struct Node* val)
{
    if((q->rear+1)%q->size == q->front)
    printf("Queue is full.");
    else{
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear]=val;
    }
}

struct Node* dequeue(struct queue *q)
{
    struct Node* x=NULL;
    if(q->front==q->rear) printf("Queue is empty.");
    else{
        q->front=(q->front+1)%q->size;
        x=q->arr[q->front];
    }
    return x;
}

