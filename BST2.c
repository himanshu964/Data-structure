   //implemantation of binary search tree
#include<stdio.h>
struct node
{
    int item;
    struct node *left;
    struct node *right;
};
void insert(int value,struct node **r)
{
        struct node *n,*pr=NULL,*ch=*r;
        n=(struct node*)malloc(sizeof(struct node));
        n->item=value;
        n->left=NULL;
        n->right=NULL;
        while(ch)
        {
            if(value>ch->item)
            {
                pr=ch;
                ch=ch->right;
            }
            else
            {
                pr=ch;
                ch=ch->left;
            }
        }
        if(*r==NULL)
        {    
            *r=n;
        }
        else
        {
             if(value>pr->item)
             {
                pr->right=n;
             } 
             else
             {
                pr->left=n;
             }
              
        }
}
void traverse( struct node *ptr)
{      
      if(ptr)
      {
    // printf("%d ",ptr->item);
      traverse(ptr->left);
      printf("%d ",ptr->item);
      traverse(ptr->right);
     //  printf("%d ",ptr->item);
      }
}
void delete(int value,struct node **r)
{
    struct node *ptr=*r,*paptr=NULL,*suc,*pasuc;
    while(ptr)
    {
        if(value==ptr->item)
        break;
        else
        {
            if(value<ptr->item)
            {
                paptr=ptr;
                ptr=ptr->left;
            }
            else
            {
                paptr=ptr;
                ptr=ptr->right;
            }
        }
    }
    if(ptr!=NULL)
    if(paptr==NULL)
    {
       if(ptr->left==NULL&&ptr->right==NULL)
       {
        *r=NULL;
        free(ptr);
       }
       else
       {
        if(ptr->left==NULL||ptr->right==NULL)
        {
            if(ptr->left==NULL)
            {
                *r=ptr->right;
                free(ptr);
            }
            else
            {
                *r=ptr->left;
                free(ptr);
            }
        }
        else
        {
           suc=ptr->right;
            pasuc=ptr;
            while(suc->left!=NULL)
            {
                pasuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            if(pasuc->left==suc)
            pasuc->left=suc->right;
            else
            pasuc->right=suc->right;
            free(suc);  
        }
       }
    }
    else
    {
    if(ptr->left==NULL&&ptr->right==NULL)
    {
           if(paptr->right==ptr)
           paptr->right=NULL;
           else
           paptr->left=NULL;
           free(ptr);
    }
    else
    {
        if(ptr->right==NULL||ptr->left==NULL)
        {
            if(paptr->right==ptr)
            {
                if(ptr->left==NULL)
                {
                    paptr->right=ptr->right;
                    free(ptr);
                }
                else
                {
                    paptr->right=ptr->left;
                    free(ptr);
                }
            }
            else
            {
              
              if(ptr->left==NULL)
                {
                    paptr->left=ptr->right;
                    free(ptr);
                }
                else
                {
                    paptr->left=ptr->left;
                    free(ptr);
                }
            }
        }
         else
         {
            
            suc=ptr->right;
            pasuc=ptr;
            while(suc->left!=NULL)
            {
                pasuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            if(pasuc->left==suc)
            pasuc->left=suc->right;
            else
            pasuc->right=suc->right;
            free(suc);
            
         }
    
    }
    }
}
int main()
{
    
   struct node *root=NULL;
   insert(50,&root);
    insert(45,&root);
    insert(60,&root);
   
   
  // insert(100,&root);
   //traverse(root);
  delete(50,&root);
  // printf("\n");
   traverse(root);
}