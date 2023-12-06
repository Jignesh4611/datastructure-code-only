#include <stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *top = NULL;
void push(char x) 
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("stake is full\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{
    struct node *t;
    char x=-1;
    if(top==NULL)
    {
        printf("stake is empty\n");
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;

}
void display()
{
    struct node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
printf("\n");
}
int main()
{
push(10);
push(20);
push(30);
display();
printf("%d",pop());
    return 0;
}