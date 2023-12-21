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
    if (q->rear == q->size - 1)
    {
        printf("queue is full\n");
    }
    else
    {
        q->rear++;
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
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d", q.Q[i]);
        printf("\n");
    }
}
int main()
{
    struct queue q;
    create(&q, 5);
    display(q);
    printf("******************\n");
    enqueue(&q, 10);
    display(q);
        printf("******************\n");
    enqueue(&q, 20);
    display(q); 
       printf("******************\n");


    enqueue(&q, 30);
    display(q);
        printf("******************\n");

    enqueue(&q, 30);
    display(q);
        printf("******************\n");

    enqueue(&q, 30);
     display(q);
         printf("******************\n");

    enqueue(&q, 30);

    display(q);
        printf("******************\n");


    return 0;
}