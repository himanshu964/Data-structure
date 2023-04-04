// #include<stdio.h>
// struct node
// {
//     int item;
//     struct node *next;
// };
// void insertAtstart(struct node **l,int data)
// {
//     struct node *n;
//     n=(struct node*)malloc(sizeof(struct node));
//     n->item=data;
//     if(*l!=NULL)
//     {
//     n->next=(*l)->next;
//     (*l)->next=n;
//     }
//     else
//     { 
//         *l=n;
//         n->next=n;
//     }
// }
// void insertAtlast(struct node **l,int data)
// {
//     struct node *n;
//     n=(struct node*)malloc(sizeof(struct node));
//     n->item=data;
//     if(*l!=NULL)
//     {
//     n->next=(*l)->next;
//     (*l)->next=n;
//     *l=n;
//     }
//     else{
//          *l=n;
//         n->next=n;
//     }
// }
// void deleteLast(struct node **l)
// {
//      struct node *r,*p;
//      r=*l;
//      p=(*l)->next;
//      if(*l==NULL)
//      printf("List is empty");
//      else{
//      while(p->next!=r)
//      {
//          p=p->next;
//      }
//      if(r==p)
//      {
//          *l=NULL;
//          free(r);
//      }
//      else{
//      p->next=(*l)->next;
//      *l=p;
//      free(r);
//      }
//      }
// }
// void deleteFirst(struct node **l)
// {
//       struct node *r;
//       r=(*l)->next;
//       if(*l!='\0'&&*l!=r)
//       {
//       (*l)->next=r->next;
//       free(r);
//       }
//       else{
//           if(*l==NULL)
//           printf("List is empty");
//           else{
//               *l=NULL;
//               free(r);
//           }
//       }
// }
// void insertAfter(struct node **l,struct node *t,int data)
// {
//      struct node *n;
//     n=(struct node*)malloc(sizeof(struct node));
//     n->item=data;
//     n->next=t->next;
//     if(t->next==*l)
//     {
//     t->next=n;
//     *l=n;
//     }
//     t->next=n;
// }
// void delete(struct node **l,struct node *t)
// {
//                       //i think traversing is required:
// }
// struct node* search(struct node *last,int data)
// {
//     struct node *t,*r;
//     r=last->next;
//     t=last->next;
//     while(t->item!=data)
//     {
//         if(t->next==r)
//         break;
//             t=t->next;
//     }
//     if(t->next==r)
//     return NULL;
//     else
//     return(t);

// }
// int main()
// {
//     struct node *last=NULL;
//     int data;
//     insertAtstart(&last,data);
// }



