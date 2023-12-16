#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *last, *t;
void create(int A[], int n)
{
    int i;
    head = (struct node *)malloc(sizeof(struct node ));
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
    while (p->next != head)
    {
        x++;
        p = p->next;
    }
    return x+1;
}
void Insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if(index<0||index > length(p))
    {
        return;
    }

    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head = NULL)
        {
            head = t;
            head->next = head;
        }

        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
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
        printf("\n");
    }
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Insert(head,2,10);
    display(head);
}