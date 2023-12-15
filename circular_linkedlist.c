#include <stdio.h>
struct node
{
    int data;
    struct node *next;
} *head, *last,*t;
void create(int A[], int n)
{
    int i;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;

for (i = 1; i < n; i++)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=A[i];
    t->next= last->next;
    last->next=t;
    last=t;
}
}