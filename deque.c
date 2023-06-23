#include<stdio.h>
#include<stdlib.h>
struct deque
{
    int capacity;
    int front,rear;
    int *ptr;
};
struct deque* create_deque(int cap)
{
   struct deque *n;
   n=(struct deque*)malloc(sizeof(struct deque));
   n->capacity=cap;
   n->front=-1;
   n->rear=-1;
   n->ptr=(int*)malloc(sizeof(int)*cap);
   return n;
}
void insertFront(int data,struct deque *q)                                //insertion at head
{
      if(q->rear==q->capacity-1&&q->front==0||q->rear+1==q->front)
      printf("deque is full");
      else{
        
        if(q->front==-1&&q->rear==-1)
        {
            q->front+=1;
            q->rear+=1;
            q->ptr[q->front]=data;
        }
        else
        {
            if(q->front==0)
            {
                q->front=q->capacity-1;
                q->front=data;
            }
            else{
                q->front-=1;
                q->ptr[q->front]=data;
            }
        }
      }
}
void insertRear(int data,struct deque *q)      //insertion at tail
{
       if(q->rear==q->capacity-1 && q->front==0||q->rear+1==q->front)
       printf("deque is full");
       else{
       if(q->front==-1&&q->rear==-1)
        {
            q->front+=1;
            q->rear+=1;
            q->ptr[q->rear]=data;
        }
        else
        if(q->rear==q->capacity)
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
void deleteFront(struct deque *q)    //deletion at head
{
  if(q->front==-1)                  //empty
  printf("underflow");
  else if(q->front==q->rear)      //single value in dequq
  {
      q->front=-1;
      q->rear=-1;
  }
  else if(q->front==q->capacity-1)   //front=cap-1;
  q->front=0;
  else
  q->front+=1;                     //front++
}
void deleteRear(struct deque *q)   //deletion at tail.
{
    if(q->rear==-1)
    printf("Underflow");
    else if(q->front==q->rear)       //single value in deque
    {
      q->front=-1;
      q->rear=-1;
    }
    else if(q->rear==0)
    q->rear=q->capacity-1;
    else
    q->rear-=1;
}
void display(struct deque *q)
{
      int i;
      i=q->front;
      while(i!=q->rear)
      {
          printf("%d,",q->ptr[i]);
          i=(i+1)%(q->capacity-1);
      }
      printf("%d",q->ptr[i]);
}
int main()
{
    struct deque *q=NULL;
    int cap,data,choice;
    q=create_deque(5);
     while(1)
    {
    printf("\n1.insertF\n2.deleteF\n3.insertR\n4.deleteR\n5.exit\n6.display\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
          case 1:
          printf("\nEnter data:");
          scanf("%d",&data);
          insertFront(data,q);
          break;

          case 2:
          deleteFront(q);
          break;

          case 3:
         
          printf("\nEnter data:");
          scanf("%d",&data);
          insertRear(data,q);
          break;

          case 4:
          deleteRear(q);
          break;

          case 5:
          exit(0);
          case 6:
          display(q);
          break;

          default:
          printf("invalid choice:");
    }
    }
}