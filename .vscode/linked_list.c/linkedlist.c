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
void sortedInsert(struct node *p, int x)
{
    struct node *t, *q = NULL;
    t = (struct node *)malloc((sizeof(struct node)));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int delete(struct node *p, int index)
{
    struct node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
        {
            q = first;
            x = first->data;
            first = first->next;
            free(q);
            return x;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int deletebyvalue(struct node *p, int y)
{
    struct node *q = NULL;
    int x = -1, i;
    for (i = 0; p->data = y; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
}

int main()
{

    // Insert(first, 0, 10);
    // Insert(first, 1, 20);
    // Insert(first, 2, 30);
    // display(first);
    sortedInsert(first, 15);
    sortedInsert(first, 25);
    sortedInsert(first, 8);
    sortedInsert(first, 9);
    sortedInsert(first, 7);
    sortedInsert(first, 11);
    sortedInsert(first, 26);
    display(first);
  
    printf("%d\n", delete (first, 4));
    display(first);
    return 0;
}