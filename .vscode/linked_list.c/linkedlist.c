#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct node
{
    int data;
    struct node *next;

} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int count(struct node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
int Rcount(struct node *p)
{
    if (p != 0)
    {
        return Rcount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}
int sum(struct node *p)
{
    int s = 0;
    while (p != 0)
    {
        s = s + p->data;
        p = p->next;
    }
    return s;
}
// MAX FOR LINKED LIST
int max(struct node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
struct node *LSearch(struct node *p, int key)
{
    struct node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
    }
    p = p->next;
}
struct node *RSearch(struct node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    return RSearch(p->next, key);
}
void Insert(struct node *p, int index, int x)

{
    struct node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {

            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    Insert(first, 0, 10);
    Insert(first, 1, 20);
    Insert(first, 2, 30);
    display(first);
    return 0;
}