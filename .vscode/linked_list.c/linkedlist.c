#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;
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
void create2(int B[], int n)
{
    int i;
    struct node *t, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = B[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = B[i];
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
int issorted(struct node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
void removeduplicate(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
void removeduplicate1(struct node *p)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        if (q != NULL && q->data == p->data)
        {
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}
void reverse1(struct node *p)
{
    int *A, i = 0;
    struct node *q = p;
    A = (int *)malloc(sizeof(int) * count(p));
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    i--;
    while (p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
    free(A);
}
void reverse2(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void reverse3(struct node *q, struct node *p)
{
    if (p != NULL)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
void concat(struct node *p, struct node *q)
{
    third = p;
    while (p->next != 0)
    {
        p = p->next;
    }
    p->next = q;
}
void merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    if (q != NULL)
        last->next = q;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {11, 22, 25, 34, 10, 55};
    create(A, 5);
    create2(B, 5);
    printf("first\n");
    display(first);
    printf("\n");

    printf("second\n");
    display(second);
    printf("\n");

    merge(first, second);
    printf("concanicated\n");
    display(third);
    printf("\n");
    return 0;
}