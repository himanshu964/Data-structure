//dynamic array data structure
#include<stdio.h>
#include<stdlib.h>
struct Array
{
  int capacity;
  int lastindex;
  int *ptr;
};
struct Array* createArray(int cap)
{
    struct Array *arr;
  arr=(struct Array*)malloc(sizeof(struct Array));
  arr->capacity=cap;
  arr->lastindex=-1; 
  arr->ptr=(int*)malloc(sizeof(int)*cap);
  return arr;
}
void insert(int data,int index,struct Array *arr)
{
  int i;
  if(index<0||index>arr->lastindex+1)
  printf("Invalid index");
  else
  {
  if(arr->lastindex==arr->capacity-1)
  {       
  doubleArray(arr);
  }
  else
  { 
    for(i=arr->lastindex;i>=index;i--)
    arr->ptr[i+1]=arr->ptr[i];
    arr->ptr[index]=data;
    arr->lastindex+=1;
  }
  }
}
void append(int data,struct Array *arr)
{
  if(arr->lastindex==arr->capacity-1) 
    doubleArray(arr);      
  
  else{
    arr->ptr[arr->lastindex+1]=data;
    arr->lastindex+=1;
  }
}
void delete(int index,struct Array *arr)
{
    int i;
    if(index<0||index>arr->lastindex)
    printf("Invalid index");
    else 
    {
      if(arr->lastindex+1==arr->capacity/2)
       halfArray(arr);
       for(i=index;i<arr->lastindex;i++)
       arr->ptr[i]=arr->ptr[i+1];
       arr->lastindex-=1;
       
      
    }
}
void edit(int data,int index,struct Array *arr)
{
    if(index<0||index>arr->lastindex)
    printf("Invalid index");
    else{
      arr->ptr[index]=data;
    }
}
void view(struct Array *arr)
{
    int i;
    for(i=0;i<=arr->lastindex;i++)
    {
      printf("%d ",arr->ptr[i]);
    }
}
void doubleArray(struct Array *arr)
{
  int *temp;
  int i;
  temp=(int*)malloc(sizeof(int)*arr->capacity*2);
  for(i=0;i<=arr->lastindex;i++)
  temp[i]=arr->ptr[i];
   free(arr->ptr);
   arr->ptr=temp;
  arr->capacity*=2;
}
void halfArray(struct Array *arr)
{
  int *temp,i;
  temp=(int*)malloc(sizeof(int)*arr->capacity/2);
  for(i=0;i<=arr->lastindex;i++)
  temp[i]=arr->ptr[i];
  free(arr->ptr);
  arr->ptr=temp;
  arr->capacity/=2;

}

int main()
{
  int choice,data,index;
  struct Array *arr;
  arr=createArray(5);
  printf("\n1.press to append in array:");
  printf("\n2.press to insert in array:");
  printf("\n3.press to view:");
  printf("\n4.press to delete an element in an array:");
  printf("\n5.press to edit");
	printf("\n6.press to exit");
 
 while(1)
 {
   printf("\nEnter a choice:");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1:
     printf("Enter data:");
    scanf("%d" ,&data);
     append(data,arr);
     break;
     case 2:
      printf("Enter index(0 to 3) no and data::");
       scanf("%d %d" ,&index,&data);
    insert(data,index,arr);
    break;

    case 3:
    view(arr);
    break;
    case 4:
    printf("Enter index number(0 to 3) which is to be deleted::");
       scanf("%d" ,&index);
    delete(index,arr);
    break;
    case 5:
     printf("Enter index(starting from 0) and data");
       scanf("%d %d",&index,&data);
    edit(data,index,arr);
    break;
    case 6:
    exit(0);
    default:
    printf("Invalid choice");
   }

 }
}
