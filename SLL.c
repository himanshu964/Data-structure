// singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int item;
  struct node *next;
};
void insertAtfirst(int data, struct node **s)
{
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  n->item = data;
  n->next = *s;
  *s = n;
}
void insertAtlast(int data, struct node **s)
{
  struct node *n, *t;
  n = (struct node *)malloc(sizeof(struct node));
  n->item = data;
  n->next = NULL;
  t = *s;
  if (t != NULL)
  {
    while (t->next != NULL)
      t = t->next;
    t->next = n;
  }
  else
  {
    *s = n;
  }
}
void deleteFirst(struct node **s)
{
  struct node *t;
  t = *s;
  if (t == NULL)
    printf("Empty list");
  else
  {
    *s = t->next;
    free(t);
  }
}
void deleteLast(struct node **s)
{
  struct node *t, *p;
  t = *s;
  p = *s;
  if (t == NULL)
    printf("Empty list");
  else
  {
    while (t->next != NULL)
      t = t->next;
    while (p->next != t)
    {
      p = p->next;
      if (p == NULL)
        break;
    }
    if (p == NULL)
      *s = NULL;
    else
      p->next = NULL;
    free(t);
  }
}
struct node *search(int data, struct node *t)
{
  if (t == NULL)
    return NULL;
  else
  {
    while (t->next != NULL)
    {
      if (t->item == data)
        return (t);
      else
        t = t->next;
    }
    if (t->item == data)
      return (t);
    else
      return NULL;
  }
}
void insertAfter(int data, struct node *t)
{
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  n->item = data;
  n->next = t->next;
  t->next = n;
}
void deleteParticular(struct node *t, struct node **s)
{
  struct node *r;
  r = *s;
  if (r == t)
  {
    *s = t->next;
    free(t);
  }
  else
  {
    while (r->next != t)
      r = r->next;
    r->next = t->next;
    free(t);
  }
}
void view(struct node *t)
{
  if (t == NULL)
    printf("Empty list::");
  else
  {
    while (t->next != NULL)
    {
      printf("%d,", t->item);
      t = t->next;
    }
    printf("%d ", t->item);
  }
}
void *reverseList(struct node *head)
{

  struct node *ptr1, *ptr2, *t;
  ptr1 = head;
  ptr2 = head;
  if (head != NULL)
  {
    if (ptr1->next == NULL)
      return head;
    else
    {
      while (ptr1->next != NULL)
        ptr1 = ptr1->next;
      t = ptr1;
      while (ptr2->next != ptr1)
      {
        ptr2 = ptr2->next;
        if (ptr2->next == ptr1)
        {
          ptr1->next = ptr2;
          ptr1 = ptr2;
          ptr2 = head;
        }
      }
      ptr1->next = ptr2;
      ptr2 = NULL;
      head = t;
    }
  }
  //return head;
}
int main()
{
  struct node *start = NULL;
  int data, choice, item;
  while (1)
  {
    printf("\n1)press 1 to insertAtfirst\n2).press 2 to insertafter\n3)press 3 to insertAtlast\n4)press 4 to deleteAtfirst\n5)press 5 to deleteNOde\n6)press 6 to deleteLast\n7)press 7 to view\n8)exit");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter data");
      scanf("%d", &data);
      insertAtfirst(data, &start);
      break;
    case 2:
      printf("Enter data to be searched and item to be inserted:");
      scanf("%d %d", &data, &item);
      if (search(data, start) == NULL)
        printf("Data not found");
      else
        insertAfter(item, search(data, start));
      break;
    case 3:
      printf("Enter data");
      scanf("%d", &data);
      insertAtlast(data, &start);
      break;
    case 4:
      deleteFirst(&start);
      break;
    case 5:
      printf("Enter data to be searched");
      scanf("%d", &data);
      if (search(data, start) == NULL)
        printf("Data not found or empty list!!!!");
      else
        deleteParticular(search(data, start), &start);
      break;
    case 6:
      deleteLast(&start);
      break;
    case 7:
      view(start);
      break;
    case 9:
      reverseList(start);
      break;
    case 8:
      exit(0);

    default:
      printf("Invalid choice");
    }
  }
}
