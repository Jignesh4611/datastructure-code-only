#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;

} *first = NULL;
void create(int A[], int n);
void insert(struct node *p, int index, int x);

int display(struct node *p);

int length(struct node *p);
int delete(struct node *p, int index);

int main()
{
    int A[] = {1, 2, 3};
    create(A, 3);
    printf("Length befere %d\n", length(first));
    delete (first, 2);
    printf("Length after %d\n", length(first));
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
void insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0 || index > length(p))
    {
        return ;
    }
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = first;
        t->prev = NULL;
        if (first != NULL)
        {
            first->prev = t;
        }
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (p->next == NULL)
        {
            p->next = t;
            t->prev = p;
            t->next = NULL;
            return;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}
int delete(struct node *p, int index)
{
    // struct node *q;
    int x = -1, i;
    if (index < 1 || index > length(p))
    {
        return -1;
    }
    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        if (p->next == NULL)
        {
            p->prev->next = NULL;
            x = p->data;
            free(p);
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}
