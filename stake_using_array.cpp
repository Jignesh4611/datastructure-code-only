#include <stdio.h>
#include <stdlib.h>

struct stack
{
  int size;
  int top;
  int *s;
};
void create(struct stack *st)
{
  printf("enter your size");
  scanf("%d", &st->size);
  st->top = -1;
  st->s = (int *)malloc(st->size * sizeof(int));
}
void push(struct stack *st, int x)
{

  if (st->top == st->size - 1)
  {
    printf("stack is overflow\n");
  }
  else
  {
    st->top++;
    st->s[st->top] = x;
  }
}
int pop(struct stack *st)
{
  int x = -1;
  if (st->top == -1)
  {
    printf("stack in under flow");
  }
  else
  {
    x = st->s[st->top];
    st->top--;
  }
  return x;
}
int display(struct stack st)
{
  for (int i = st.top; i >= 0; i--)
  {
    printf("%d", st.s[i]);
  }
  printf("\n");
}
int main()
{
  struct stack st;
  create(&st);
  int x;
  int a;
  while (1)
  {

    printf("enter 1 for push and 2 for pop and 3 for display");
    scanf("%d", &x);

    switch (x)

    {
    case 1:
      printf("enter push item : ");
      scanf("%d", &a);
      push(&st, a);
      break;
    case 2:
      a = pop(&st);
      if (a != -1)
      {
        printf("item poped %d\n",a);
      }
      break;
    case 3:
      display(st);
      break;
    }
  }
  return 0;
}