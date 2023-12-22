#include <stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q, int size);
void enqueue(struct queue *q, int x);
int dequeue(struct queue *q);
void display(struct queue q);
int main()
{
    struct queue q;
    create(&q, 4);
    enqueue(&q, 12);
    enqueue(&q, 12);
    enqueue(&q, 12);
   dequeue(&q);
   dequeue(&q);
   dequeue(&q);

        
printf("%d",q.front);

    display(q);
}
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("queue is full");
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int  dequeue(struct queue *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        printf("queue is empty ");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void display(struct queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}