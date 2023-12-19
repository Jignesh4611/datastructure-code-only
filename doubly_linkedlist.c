#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;

} *first = NULL;
void create(int A[], int n);
int display(struct node *p);

int length(struct node *p);


int main()
{
    int A[] = {1, 2, 3};
    create(A,4);

   printf("length is %d\n",length(first)) ;
    display(first);
    return 0;
}
void create(int A[], int n)
{
    struct node *t, *last;
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
int length(struct node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
int display(struct node *p)
{
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}