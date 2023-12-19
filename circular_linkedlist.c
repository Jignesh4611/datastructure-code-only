#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head, *last;
void create(int A[], int n);
int length(struct node *p);
void Insert(struct node *p, int index, int x);
void display(struct node *h);
int delete(struct node *p, int index);

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    create(A, 6);

    display(head);
    delete (head, 2);
    display(head);
    display(last);
}

void create(int A[], int n)
{
    struct node *t;
    int i;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}
int length(struct node *p)
{
    int x = 0;
    do
    {
        x++;
        p = p->next;
    } while (p != head);
    return x;
}
// before that position
void Insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0 || index > length(p))
    {
        return;
    }

    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
            last = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 1; i < index - 2; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
        last = t;
    }
}

void display(struct node *h)
{
    if (head == NULL)
    {
        printf("linked list is Null");
    }
    else
    {
        do
        {
            printf("%d ", h->data);
            h = h->next;
        } while (h != head);
    }
    printf("\n");
}
int delete(struct node *p, int index)
{
    struct node *q;
    int i, x;
    if (index < 0 || index > length(head))
    {
        return -1;
    }

    if (index == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {

        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}
