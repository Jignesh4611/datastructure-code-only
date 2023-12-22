#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q, int size);
void rear_enqueue(struct queue *q, int x);
int rear_dequeue(struct queue *q);
void front_enqueue(struct queue *q, int x);
int front_dequeue(struct queue *q);
void display(struct queue q);
int main()
{
    struct queue q;
    rear_enqueue(&q, 1);
    rear_enqueue(&q, 1);
    rear_enqueue(&q, 1);

    display(q);
}
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}
void rear_enqueue(struct queue *q, int x)
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
int rear_dequeue(struct queue *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        printf("queue is empty ");
    }
    else
    {
        q->rear--;
        x = q->Q[q->rear--];
    }
    return x;
}
void front_enqueue(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("queue is full");
    }
    else
    {
        q->front--;
        q->Q[q->front--] = x;
    }
}
int front_dequeue(struct queue *q)
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