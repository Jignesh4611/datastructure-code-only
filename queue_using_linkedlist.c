#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *front = NULL, *rear = NULL;
void enqueue(int x);
int dequeue();
void display();
int main()
{
    struct node *q;
    enqueue(30);
    enqueue(30);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
void enqueue(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("queue is full");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next=t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct node *t;

    if (rear == front)
    {
        printf("dequeue is not possible");
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
void display()
{
    struct node *h = front;
    int i;
    while (h!= NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}
