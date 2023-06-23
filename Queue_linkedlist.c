//Queue using linkedlist
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
void insertion(int data,struct node **front,struct node **rear)
{
     struct node *n;
     n=(struct node*)malloc(sizeof(struct node));
     n->item=data;
     if(*front==NULL)
     {
     n->next='\0';
     *front=n;
     *rear=n;
     }
     else
     {
     n->next=(*rear)->next;
     (*rear)->next=n;
     *rear=n;
     }

}
void deletion(struct node **front,struct node **rear)
{
    struct node *t;
    t=*front;
    if(*front==*rear)
    *rear=NULL;
    *front=t->next;
    free(t);
}
void getFront(struct node *front)   //funtion to view front value
{
    if(front==NULL)
    printf("Queue is empty");
    else
    printf("%d",front->item);  
}
int main()
{
   struct node *front=NULL,*rear=NULL;
   int choice,data;
    while(1)
    {
        printf("\npress 1 for insertion:\npress 2 for deletion\npress 3 for view front value\npress 4 for exit");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
          printf("\nEnter data:");
          scanf("%d",&data);
          insertion(data,&front,&rear);
          break;
          case 2:
          deletion(&front,&rear);
          break;
          case 3:
          getFront(front);
          break;
          case 4:
          exit(0);
          default:
          printf("Invalid choice");
          break;
        }
    }
}
