#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
struct node *root = NULL;
void treecreate()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);
    printf("enter root value :");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("enter left child %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {

            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter right child %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {

            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct node *p)
{
    if (p)
    {
        printf(" %d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    treecreate();
    preorder(root);
    return 0;
}