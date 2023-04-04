#include<stdio.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *prev;
    struct node *next;
};
void insertAtstart(int data,struct node **s)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->prev='\0';
    n->next=*s;
    if(*s!=NULL)
    (*s)->prev=n;
    *s=n;
}
void insertAtlast(int data,struct node **s)
{
    struct node *n,*t;
    t=*s;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->next=NULL;
    if(t!=NULL)
    {
    while(t->next!=NULL)
    t=t->next;
    t->next=n;
    }
    else
    *s=n;
    n->prev=t;
}
void deleteFirst(struct node **s)
{
    struct node *t;
    t=*s;
    if(t==NULL)
    printf("List is empty");
    else{
        if(t->next!=NULL)
        t->next->prev=NULL;
       *s=t->next;
       free(t); 
    }
}
void deleteLast(struct node **s)
{
    struct node *t;
    t=*s;
    while(t->next!=NULL)
    t=t->next;
    if(t->prev!=NULL)
    t->prev->next=NULL;
    else
    *s=NULL;
    free(t);
}
struct node* search(int data,struct node *start)
{
    while(start)
    {
        if(start->item==data)
        return start;
        start=start->next;
    }
    return NULL;
}
void insertAfter(int data,struct node *t)//10 and 2000;
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->item=data;
    n->prev=t;
    n->next=t->next;
    if(t->next!=NULL)
    t->next->prev=n;
    t->next=n;
}
void deleteNode(struct node *t,struct node **s)
{
    if(t->prev!=NULL)
    t->prev->next=t->next;
    if(t->next!=NULL)
    t->next->prev=t->prev;
    if(t->prev==t->next)
    *s=NULL;
    free(t);
}
void view(struct node *t)
{
    if(t=='\0')
    printf("List is empty bro");
    else
    {
     while(t->next!=NULL)
     {
         printf("%d,",t->item);
         t=t->next;
     }
     printf("%d",t->item);
    }
}

int main()
{
    struct node *start=NULL;
     int choice,data,item;
    while(1)
    {
    printf("\n1)press 1 to insertAtstart\n2)press 2 to insertAfter\n3)press 3 to insertAtlast\n4)press 4 to deletefirst\n5)press 5 to deleteNOde\n6)press 6 to deleteLast\n7)press 7 to view\n8)exit");
         printf("\nEnter your choice:");
         scanf("%d",&choice);
         switch (choice)
         {
            case 1:
            printf("\nEnter data:");
            scanf("%d",&data);
            insertAtstart(data,&start);
            break;

            case 2:
            printf("\nEnter data to which after node is inserted:");
            scanf("%d",&data);
            printf("\nEnter item:");
            scanf("%d",&item);
            insertAfter(item,search(data,start));
            break;

            case 3:
            printf("\nEnter data:");
            scanf("%d",&data);
            insertAtlast(data,&start);
            break;

            case 4:
            deleteFirst(&start);
            break;

            case 5:
            printf("\nEnter data to which after node is deleted:");
            scanf("%d",&data);
            deleteNode(search(data,start),&start);
            break;

            case 6:
            deleteLast(&start);
            break;

            case 7:
            view(start);
            break;

            case 8:
            exit(0);

            default:
            printf("Invalid choice");
         }
    }
}