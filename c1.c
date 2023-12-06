#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
void insertPosition (int data, int pos, struct Node **head)	

{
  struct Node *newnode, *curNode;
  int i;

  if (*head == NULL)
    {
      printf ("List is empty");
    }
  if (pos == 1)
    {
      insertStart (head, data);
      return;
    }
  else
    {
      newnode = (struct Node *) malloc (sizeof (struct Node));
      newnode->data = data;
      curNode = *head;
      while (--pos > 1)
	{
	  curNode = curNode->next;
	}
      newnode->next = curNode->next;
      curNode->next = newnode;
    }
}
void display (struct Node *head)
{
  if (head == NULL)
    return;
  struct Node *temp = head;
  do
    {
      printf ("%d ", temp->data);
      temp = temp->next;

    }
  while (temp != head);
  printf ("\n");
}

int main ()
{
  struct Node *head = NULL;
  printf("Insert at Specific Position: ");
  insertPosition (5, 3, &head);
  display (head);
  return 0;
}