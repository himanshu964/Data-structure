//program on stack
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int capacity;
    int *ptr;
};
struct stack* createstack(int cap)
{
    struct stack *n;
    n=(struct stack*)malloc(sizeof(struct stack));
    n->top=-1;
    n->ptr=(int*)malloc(sizeof(int)*cap);
    n->capacity=cap;
    return(n);
}
void push(struct stack *n,int data)
{
     if(n->top==n->capacity-1)
     printf("Overflow\n");
     else{
        n->ptr[n->top+1]=data;  
        n->top+=1; 
     }
}
void pop(struct stack *n)
{
       if(n->top>-1)
       n->top-=1;                      //if(n->top==-1)
       else                            //printf("stack underflow")
       printf("Stack Underflow\n");    //else
}                                      //n->top-=1;
void peek(struct stack *n)
{
     if(n->top==-1)
     printf("Empty stack\n");
     else
      printf("%d\n",n->ptr[n->top]);
}
int main()
{
    struct stack *n;
    int size,choice,data;
    printf("Enter size of array:\n");
    scanf("%d",&size);
   n=createstack(size);
   while(1)
   {
       printf("press 1 to push\npress 2 to pop\npress 3 to peek\npress 4 to exit");
       printf("\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
         case 1:
         printf("\nEnter data:");
         scanf("%d",&data);
         push(n,data);
         break;

         case 2:
         pop(n);
         break;

         case 3:
         peek(n);
         break;
         

         case 4:
         exit(0);
         default:
         printf("Invalid choice\n");
       }
   }
}


