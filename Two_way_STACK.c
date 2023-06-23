//Two way stack(variation of stack)
#include<stdio.h>
#include<stdlib.h>
struct STACK
{
    int top1,top2;
    int *ptr;
    int capacity;
};
struct STACK* createArray(int cap)
{
    struct STACK *q;
    q=(struct STACK*)malloc(sizeof(struct STACK));
    q->capacity=cap;
    q->top1=-1;
    q->top2=cap;
    q->ptr=(int*)malloc(sizeof(int)*cap);
    return(q);
}
void push1(struct STACK *q,int data)
{
    if(q->top1+1==q->top2)
    printf("\noverflow");
    else{
      q->top1+=1;
      q->ptr[q->top1]=data;
    }
}
void push2(struct STACK *q,int data)
{
    if(q->top1+1==q->top2)
    printf("\noverflow");
    else{
    q->top2-=1;
    q->ptr[q->top2]=data;
    }
}
void pop1(struct STACK *q)
{
    if(q->top1==-1)
    printf("\nSTACK 1 is underflow");
    else{
       q->top1-=1; 
    }
}
void pop2(struct STACK *q)
{
    if(q->top2==q->capacity)
    printf("\nSTACK 2 is underflow\n");
    else{
        q->top2+=1;
    }
}
void peek1(struct STACK *q)
{
  if(q->top1==-1)
  printf("\nSTACK1 is empty\n");
  else
  printf("\n%d\n",q->ptr[q->top1]);
}

void peek2(struct STACK *q)
{
  if(q->top2==q->capacity)
  printf("STACK2 is empty\n");
  else
  printf("\n%d\n",q->ptr[q->top2]);
}


int main()
{
    struct STACK *q;
    int cap,choice,data;
    printf("Enter size of array:\n");
    scanf("%d",&cap);
    q=createArray(cap);
    while(1)
    {
        printf("press 1 for push1\npress 2 for push2\npress 3 to pop1\npress 4 to pop2\npress 5 to view top1\npress 6 to view top2\npress 7 for exit");
        printf("\nEnter choice::");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("\nEnter data:");
         scanf("%d",&data);
         push1(q,data);
         break;
         case 2:
         printf("\nEnter data:");
         scanf("%d",&data);
         push2(q,data);
         break;
         case 3:
         pop1(q);
         break;
         case 4:
         pop2(q);
         break;
         case 5:
         peek1(q);
         break;
         case 6:
         peek2(q);
         break;
         case 7:
         exit(0);
        default:
        printf("\ninvalid choice");
        }
    }

}