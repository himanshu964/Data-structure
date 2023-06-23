//program on priority queue
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    int priority;
    struct node *next;
};
void insertion(struct node **s,int data,int priority_no)
{
    struct node *n,*t;
    n=(struata;
    n->priority=priority_no;
    n->next=NULL;ct node*)malloc(sizeof(struct node));
    n->item=d
    t=*s;
    if(*s==NULL)
    {
        *s=n;
    }
    else
    {
        if(n->priority>(*s)->priority)
        {
          n->next=*s;
          *s=n;
        }
         else
         {
            while(t->next!=NULL&&t->next->priority>=n->priority)
            {
                t=t->next;
            }
             
            n->next=t->next;
            t->next=n;
         }

    }    
}
void delete(struct node **s)
{
   struct node *t;
   if(*s==NULL)
   printf("\nqueue is empty");
   else
   {
   t=*s;
   *s=t->next;
   free(t);
   }
}
void viewQueue(struct node *s)
{
    
    while(s!=NULL)
    {
        printf("%d,",s->item);
        s=s->next;
    }
}
int main()
{
    struct node *start=NULL;
    int choice,data,pr;
    while(1)
    {
    printf("\n1.insert\n2.delete\n3.viewqueue\n4.exit\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
          case 1:
          printf("\nEnter data and priority:");
          scanf("%d %d",&data,&pr);
          insertion(&start,data,pr);
          break;

          case 2:
          delete(&start);
          break;

          case 3:
          viewQueue(start);
          break;

          case 4:
          exit(0);

          default:
          printf("invalid choice:");
    }
    }

}
*/
