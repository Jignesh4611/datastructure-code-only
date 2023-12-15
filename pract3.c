#include<stdio.h>

int stack[5];
int top = -1;
int max = 5;

void Push()
{
    int a;
    if (top == max - 1)
    {
        printf("\nStack is full\n");
    }
    else
    {
        top++;
        printf("Enter the element to push:");
        scanf("%d", &a);
        stack[top] = a;
    }
}
void Pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        top--;
    }
}

void Peep()
{
    int a;
    printf("Enter the index to peep:\n");
    scanf("%d", &a);
    if (a <= top && a > -1)
    {
        int ans = top - a;
        printf("Value at index %d is %d", a, stack[ans]);
        printf("\n");
    }
    else
    {
        printf("No such index present in the stack\n");
    }
}

void Change()
{
    int index, value;
    printf("Enter the index to change:");
    scanf("%d", &index);
    if (index <= top && index > -1)
    {
        printf("Enter the new value to insert:");
        scanf("%d", &value);
        stack[index] = value;
    }
    else
    {
        printf("NO index present\n");
    }
}

int Display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, x, y;
    while (1)
    {
        printf("Enter the choice:\n");
        printf("1)Push ---- \n");
        printf("2)Pop ----- \n");
        printf("3)Peep ---- \n");
        printf("4)Change ----- \n");
        printf("5)Display ----- \n");
        printf("6)Exit --- \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peep();
            break;
        case 4:
            Change();
            break;
        case 5:
            Display();
            break;
        default:
            exit(0);
        }
    }
} 
