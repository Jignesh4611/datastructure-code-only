#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
int isoperand(char x);
void push(int x);
int pop();
int eval(char * postfix);
int main ()
{
   char *postfix="234*+82/-";
   printf("result is %d",eval(postfix));
return 0;
}
int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void push(int x)

{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
    {
        printf("stake is full\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int pop()
{
    struct node *t;
    int x = -1;
    if (top == NULL)
    {
        printf("stake is empty\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int eval(char * postfix)
{
    int i ,x1,x2,r;
    for (i=0; postfix[i]!='\0'; i++)
    {
        if(isoperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop(); x1=pop();
            switch(postfix[i])
            {
                case '+':r=x1+x2; break;
                case '-':r=x1-x2; break;
                case '*':r=x1*x2; break;
                case '/':r=x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}