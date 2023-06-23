//program on queue using array.
#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};
struct Queue* createQueue(int cap)
{
    struct Queue *q;
    q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=cap;
    q->front=-1;
    q->rear=-1;
    q->ptr=(int*)malloc(sizeof(int)*cap);
    return q;
}
void insertion(struct Queue *q,int data)
{
    if(q->rear==q->capacity-1&&q->front==0||q->rear+1==q->front)
    printf("overflow");
    else
    {
        if(q->rear==-1)
        {
            q->rear+=1;
            q->front+=1;
            q->ptr[q->rear]=data;
        }
        else
        {
            if(q->rear==q->capacity-1)
            {
                q->rear=0;
                q->ptr[q->rear]=data;
            }
            else{
                q->rear+=1;
                q->ptr[q->rear]=data;
            }
        }
    }
}
void deletion(struct Queue *q)
{
      if(q->front==-1)
      printf("Underflow");
      else
      {
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }
        else
        {
            if(q->front==q->capacity-1)
            q->front=0;
            else{
                q->front+=1;
            }
        }
      }   
}
void viewgetfront(struct Queue *q)
{
    if(q->front==-1)
    printf("Queue is empty");
    else
    printf("%d",q->ptr[q->front]);
}
int main()
{
    struct Queue *Q=NULL;
    int cap,choice,data;
    printf("\nEnter size of array::");
    scanf("%d",&cap);
    Q=createQueue(cap);
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
          insertion(Q,data);
          break;
          case 2:
          deletion(Q);
          break;
          case 3:
          viewgetfront(Q);
          break;
          case 4:
          exit(0);
          default:
          printf("Invalid choice");
        }
    }
}