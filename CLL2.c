#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
void insertAtstart(int data,struct node **l)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data; 
    if(*l!=NULL)
    {
    n->next=(*l)->next;
    (*l)->next=n;
    }
    else{
        n->next=n;
        *l=n;
    }
}
void insertAtlast(int data,struct node **l)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data; 
    if(*l!=NULL)
    {
    n->next=(*l)->next;
    (*l)->next=n;
    }
    else 
    {
        n->next=n;
    }
    *l=n;
}
void deleteFirst(struct node **l)
{
    struct node *t;
    t=(*l)->next;
    if(t==*l)
    *l=NULL;
    else
    (*l)->next=t->next;
    free(t);
}
void deleteLast(struct node **l)
{
    struct node *t;
    t=(*l)->next;
    while(t->next!=*l)
    t=t->next;
     if(t==*l)
    {
       *l=NULL;
        free(t);
    }
    else
    {
    t->next=(*l)->next;
    free(*l);
    *l=t;
    }

}
void insertAfter(int data ,struct node *t,struct node **l)
{
     struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->item=data; 
    n->next=t->next;
    t->next=n;
    if(t==*l)
    *l=n;

}
void deleteNode(struct node *t,struct node **l)
{
      struct node *r;
      r=(*l)->next;
      while(r->next!=t)
      r=r->next;
      r->next=t->next;
      if(t==*l)
      *l=r;
      free(t);  
}
struct node* search(int data,struct node *last)
{
   struct node *t,*r;
   t=last->next;
   r=t;
   while(t->next!=r)
   {
       if(t->item==data)
       return t;
       t=t->next;
   }
   if(t->item==data)
   return t;
   else 
   return NULL;
}
void view(struct node *last)
{
   struct node *t;
   if(last==NULL)
   printf("Empty list");
   else
   {
   t=last->next;
   while(t->next!=last->next)
   {
       printf("%d,",t->item);
       t=t->next;
   }
   printf("%d",t->item);
   }
}
int main()
{
    struct node *last=NULL;
    int choice,data,item;
    while(1)
    {
        printf("\n1)press 1 to insertAtfirst\n2)press 2 to insertafter\n3)press 3 to insertAtlast\n4)press 4 to deleteAtfirst\n5)press 5 to deleteNOde\n6)press 6 to deleteLast\n7)press 7 to view\n8)exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter data");
            scanf("%d" ,&data);
            insertAtstart(data,&last);
            break;
            case 2:
            printf("\nEnter item for searching and data value");
            scanf("%d %d" ,&item,&data);
            insertAfter(data,search(item,last),&last);
            break;
            case 3:
            printf("\nenter data:");
            scanf("%d",&data);
            insertAtlast(data,&last);
            break;
            case 4:
            deleteFirst(&last);
            break;
            case 5:
            printf("Enter data which is to be deleted");
            scanf("%d",&data);
            deleteNode(search(data,last),&last);
            break; 
            case 6:
            deleteLast(&last);
            break;
            case 7:
            view(last);
            break;
            case 8:
            exit(0);
            default:
            printf("Invalid chice");

            
            

        }
    }

}