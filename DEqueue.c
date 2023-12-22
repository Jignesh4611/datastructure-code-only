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
    create(&q, 4);

    rear_enqueue(&q, 1);
    rear_enqueue(&q, 2);
    rear_enqueue(&q, 3);
    front_dequeue(&q);
    front_dequeue(&q);
    front_enqueue(&q, 21);
    front_enqueue(&q, 21);
    rear_dequeue(&q);
    printf("   %d \n ", q.front);
    printf("   %d \n ", q.rear);

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

        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}
void front_enqueue(struct queue *q, int x)
{
    if (q->front == -1)
    {
        printf("en_queue is not possible\n");
    }
    else
    {

        q->Q[q->front] = x;
        q->front--;
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