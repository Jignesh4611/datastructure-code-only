void Insert(struct node *p, int index, int x)
// {
//     struct node *t;
//     int x, i;
//     if (index < 0 || index > lenght)
//     {
//         return;
//     }

//     if (index == 0)
//     {
//         t = (struct node *)malloc(sizeof(struct node));
//         t->data = x;
//         if (head = NULL)
//         {
//             head = t;
//             head->next = head;
//         }

//         else
//         {
//             while (p->next != head)
//             {
//                 p = p->next;
//             }
//             p->next = t;
//             t->next = head;
//         }
//     }

//     {
//         for (i = 0; i < index - 1; i++)
//         {
//             t = (struct node *)malloc(sizeof(struct node));
//             t->data = x;
//             t->next = p->next;
//             p->next = t;
//         }
//     }
// }
// int lenght(struct node *p)
// {
//     int x = 0;
//     while (p->next != head)
//         {
//             x++;
//             p=p->next;
//         }
//     return x;
// }