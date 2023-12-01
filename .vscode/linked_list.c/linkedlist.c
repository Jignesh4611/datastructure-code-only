#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
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
    if(p!=0)
    {
        return Rcount(p->next)+1;
    }
    else 
    {return 0;}
}
int sum (struct node *p)
{
    int s=0;
    while (p!=0)
    {
       s=s+p->data;
       p=p->next; 
    }
    return s;
}
// MAX FOR LINKED LIST
int max(struct node *p)
{
    int max= INT32_MIN;
    while (p)
    {
        if(p->data>max)
        max=p->data;
        p=p->next;

    }
    return max;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 9, 9.9};
    create(A,9);
    printf("%d",max(first));
    return 0;
}