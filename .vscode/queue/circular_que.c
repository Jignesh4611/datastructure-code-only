// abstract data typre of queue
// queue is empty -front is equal to  rear
#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q, int size1)
{
    q->size = size1;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void enqueue(struct queue *q, int x)
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
int dequeue(struct queue *q)
{
    int x = -1;
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
void display(struct queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d", q.Q[i]);
        printf("\n");
    }
}
int main()
{
    struct queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    dequeue(&q);
    printf("\n");
    display(q);
    return 0;
}