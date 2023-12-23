#include <stdio.h>
#include <stdlib.h>
struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};
void create(struct queue *q, int size1)
{
    q->size = size1;
    q->front = q->rear = -1;
    q->Q = (struct node**)malloc(q->size * sizeof(struct node *));
}
void enqueue(struct queue *q,struct node *x)
{
    if ((q->rear +1)%q->size==q->front)
    {
        printf("queue is full");
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}
struct node * dequeue(struct queue *q)
{
   struct  node* x =NULL;
    if (q->rear == q->front)
    {
        printf("queue is empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
int isempty(struct queue q)
{
    return q.front==q.rear;
}