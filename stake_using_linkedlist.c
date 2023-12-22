#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
};
struct node *top = NULL;
void push(char x)
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
char pop()
{
    struct node *t;
    char x = -1;
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
void display()
{
    struct node *p;
    p = top;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}
int isbalance(char *exp)
{
    top = NULL;
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int outpre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else if (x == '^')
    {
        return 6;
    }
    else if (x == '(')
    {
        return 7;
    }
    else if (x == ')')
    {
        return 0;
    }
    return -1;
}
int inpre(char x)
{
    if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 5;
    }
    else if (x == '(')
    {
        return 0;
    }
    return -1;
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
char *intopost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (outpre(infix[i]) > inpre(top->data))
            {
                push(infix[i++]);
            }
            else if (outpre(infix[i]) == inpre(top->data))
            {
                pop();
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL && top->data != ')')
    {

        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    push('#');
    char *postfix = intopost(infix);
    printf("%s ", postfix);
       printf("%c",top->next);
    return 0;
 
}