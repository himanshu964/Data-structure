#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
/*void push(int data,struct node **s)        //here traversing is requied so this is not efficient
{
    struct node *n,*t;
    t=*s;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    if(t==NULL)
    {
    n->next=NULL;
    *s=n;
    }
    else
    {
    while(t->next!=NULL)
    t=t->next;
    n->next=t->next;
    t->next=n;
    }
}
void pop(struct node **s)
{
    struct node *t;
    t=*s;
    while()
}

int main()
{
    
}*/
void push(int data,struct node **t)      //here traversing is not required so it is efficient method.
{
    struct node *n;
     n=(struct node*)malloc(sizeof(struct node));
    n->item=data;
    n->next=*t;
    *t=n;
}
void pop(struct node **t)
{
    
    struct node *r;
    if(*t==NULL)
    printf("Stack Underflow\n");
    else{
    r=*t;
    *t=r->next;
    free(r);
    }
    
}
void peek(struct node *t)
{
      if(t==NULL)
      printf("Empty stack\n");
      else
      {
          printf("%d\n",t->item);
      }
}
int main()
{
    struct node *start=NULL;
    int choice,data;

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
         push(data,&start);
         break;

         case 2:
         pop(&start);
         break;

         case 3:
         peek(start);
         break;
         

         case 4:
         exit(0);
         default:
         printf("Invalid choice\n");
       }
   }
}

